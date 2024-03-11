#include <iostream>
#include <sc-agents-common/utils/GenerationUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/IteratorUtils.hpp>
#include "HordsAgent.hpp"

using namespace std;
using namespace utils;

namespace exampleModule
{
    
SC_AGENT_IMPLEMENTATION(HordsAgent)
{
  ScAddr actionNode = otherAddr;
  ScAddr inputGraphStruct = IteratorUtils::getAnyFromSet(ms_context.get(), actionNode);
  if(!inputGraphStruct.IsValid())
  {
  SC_LOG_ERROR("HordsAgent: Invalid argument");
  utils::AgentUtils::finishAgentWork(&m_memoryCtx,actionNode,false);
  return SC_RESULT_ERROR_INVALID_PARAMS;
  }
  ScAddrVector answerElements;
  if (noOrientCheck(inputGraphStruct)==false)
  {
     SC_LOG_ERROR("Graph is directed");
     answerConstructionForOriented(inputGraphStruct,answerElements);
     utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, answerElements, true);
     return SC_RESULT_OK;
  }
   vector<Cycle> cycles=findCycles(inputGraphStruct);
   if (cycles.size()==0)
  {
    SC_LOG_ERROR("No cycles in graph");
    answerConstructionForAcyclic(inputGraphStruct,answerElements);
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, answerElements, true);
    return SC_RESULT_OK;
  }
    ScAddrVector hords=getHords(cycles,inputGraphStruct); 
     if (hords.empty())
  {
    SC_LOG_ERROR("No hords in graph");
    answerConstructionForUnchordal(inputGraphStruct,answerElements);
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, answerElements, true);
    return SC_RESULT_OK;
  }
  answerConstructionSuccesfull(inputGraphStruct,answerElements,hords);
  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, answerElements, true);
  SC_LOG_DEBUG("succesfully");
  return SC_RESULT_OK;
}

void HordsAgent::answerConstructionSuccesfull( ScAddr const & inputGraphStruct,ScAddrVector & answerElements,ScAddrVector hords)
{ 
   answerElements.push_back(Keynodes::HordClass);
   answerElements.push_back(Keynodes::nrel_hord);
    for(auto hord:hords)
    {
       
       ScAddr HordEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm,Keynodes::HordClass,hord);
       ScAddr relation = m_memoryCtx.CreateEdge(ScType::EdgeDCommonConst, hord,inputGraphStruct);
       ScAddr hordsRelation = m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::nrel_hord, relation);
       answerElements.push_back(hord);
       answerElements.push_back(HordEdge);
       answerElements.push_back(relation);
       answerElements.push_back(hordsRelation);
   }
    
   ScAddr chordalGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::ChordalGraphClass,inputGraphStruct);
   ScAddr cyclicGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::CyclicGraphClass,inputGraphStruct);
   ScAddr undirectedGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::UndirectedGraphClass,inputGraphStruct); 
   answerElements.push_back(chordalGraphEdge);
   answerElements.push_back(Keynodes::ChordalGraphClass);
   answerElements.push_back(cyclicGraphEdge);
   answerElements.push_back(Keynodes::CyclicGraphClass);
   answerElements.push_back(undirectedGraphEdge);
   answerElements.push_back(Keynodes::UndirectedGraphClass);
  
  
}
void HordsAgent::answerConstructionForUnchordal( ScAddr const & inputGraphStruct,ScAddrVector & answerElements)
{ 
    ScAddr undirectedGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::UndirectedGraphClass,inputGraphStruct);
    ScAddr cyclicGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::CyclicGraphClass,inputGraphStruct);
    ScAddr unchordalGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::UnchordalGraphClass,inputGraphStruct);
    answerElements.push_back(unchordalGraphEdge);
    answerElements.push_back(Keynodes::UnchordalGraphClass);
    answerElements.push_back(cyclicGraphEdge);
    answerElements.push_back(Keynodes::CyclicGraphClass);
    answerElements.push_back(undirectedGraphEdge);
    answerElements.push_back(Keynodes::UndirectedGraphClass);
}
void HordsAgent::answerConstructionForAcyclic( ScAddr const & inputGraphStruct,ScAddrVector & answerElements)
{ 
    ScAddr undirectedGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::UndirectedGraphClass,inputGraphStruct);
    ScAddr acyclicGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::AcyclicGraphClass,inputGraphStruct);
    ScAddr unchordalGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::UnchordalGraphClass,inputGraphStruct);
     answerElements.push_back(unchordalGraphEdge);
    answerElements.push_back(Keynodes::UnchordalGraphClass);
    answerElements.push_back(acyclicGraphEdge);
    answerElements.push_back(Keynodes::AcyclicGraphClass);
     answerElements.push_back(undirectedGraphEdge);
    answerElements.push_back(Keynodes::UndirectedGraphClass);
}
void HordsAgent::answerConstructionForOriented( ScAddr const & inputGraphStruct,ScAddrVector & answerElements)
{ 
    ScAddr directedGraphEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::DirectedGraphClass,inputGraphStruct);
    answerElements.push_back(directedGraphEdge);
    answerElements.push_back(Keynodes::DirectedGraphClass);
}
bool HordsAgent::noOrientCheck(ScAddr const & inputGraphStruct)
{
    ScAddrVector graphNodes;
    ScIterator3Ptr it3_0 = m_memoryCtx.Iterator3(
    inputGraphStruct,
    ScType::EdgeAccessConstPosPerm,
    ScType::NodeConst);
    while (it3_0->Next())
    {
        graphNodes.push_back( it3_0->Get(2) );
    }
    for(auto node:graphNodes)
    {
       ScAddrVector neighbourNodes;
       ScIterator5Ptr it5 = m_memoryCtx.Iterator5(
        node,                                         // ->Get(0)
        ScType::EdgeAccessConstPosPerm,              // ->Get(1)
        ScType::NodeConst,                          // ->Get(2)
        ScType::EdgeAccessConstPosPerm,            // ->Get(3)
        inputGraphStruct);                        // ->Get(4)
        while (it5->Next())
     {
      neighbourNodes.push_back(it5->Get(2));
     }
      if(neighbourNodes.size()==0) continue;
      else return false;
    }

     return true;
}

vector<Cycle> HordsAgent::findCycles(ScAddr const & inputGraphStruct)
{

    vector<Cycle> result;
    ScAddrVector graphNodes;
    ScIterator3Ptr it3=m_memoryCtx.Iterator3(
    inputGraphStruct,
    ScType::EdgeAccessConstPosPerm,
    ScType::NodeConst);
     while (it3->Next())
    { 
       graphNodes.push_back( it3->Get(2) );
    }
    for (auto node : graphNodes)
    {
   
        Cycle cycle;
        ScAddrVector vn;
        vector<Cycle> cycles;
        dfs(node,node,vn,cycles,cycle,inputGraphStruct);
        for(auto cycle:cycles)
        {
        result.push_back(cycle);
        }
      
    }
   
    return result;
}
void HordsAgent::dfs(ScAddr startNode,ScAddr currentNode,ScAddrVector vn,vector<Cycle>& result,Cycle cycle,ScAddr const & inputGraphStruct)
{
    if(startNode==currentNode && !vn.empty())
    {
       result.push_back(cycle);
       return;
    }
   auto iter=find(vn.begin(),vn.end(),currentNode);
   if(iter!=vn.end()) {
   return;
   }
   vn.push_back(currentNode); 
   cycle.push_back(currentNode);
       ScAddrVector currentNeighbourNodes;
       ScIterator5Ptr it5_1 = m_memoryCtx.Iterator5(
        currentNode,                                  // ->Get(0)
        ScType::EdgeUCommonConst,                    // ->Get(1)
        ScType::NodeConst,                          // ->Get(2)
        ScType::EdgeAccessConstPosPerm,            // ->Get(3)
        inputGraphStruct);                        // ->Get(4)
        while (it5_1->Next())
     {
 
      currentNeighbourNodes.push_back(it5_1->Get(2));
     }
     ScIterator5Ptr it5_2 = m_memoryCtx.Iterator5(
        ScType::NodeConst,                            // ->Get(0)
        ScType::EdgeUCommonConst,                    // ->Get(1)
        currentNode,                                // ->Get(2)
        ScType::EdgeAccessConstPosPerm,            // ->Get(3)
        inputGraphStruct);                        // ->Get(4)
        while (it5_2->Next())
     {
      
      currentNeighbourNodes.push_back(it5_2->Get(0));
     }
      
    for(auto node:currentNeighbourNodes)
    {
        if(cycle.size()>1 && cycle[cycle.size()-2]==node) continue;
        dfs(startNode,node,vn,result,cycle,inputGraphStruct);
    }
}
ScAddrVector HordsAgent::getHords(vector<Cycle> cycles,ScAddr const & inputGraphStruct)
{
    ScAddrVector result;

    for(auto cycle:cycles)
    {
        if(cycle.size()<4) continue;
          
            for(int i=0;i<cycle.size();i++){
            

                ScIterator5Ptr it5_1= m_memoryCtx.Iterator5(
                cycle[i],
                ScType::EdgeUCommonConst,
                ScType::NodeConst,
                ScType::EdgeAccessConstPosPerm,
                inputGraphStruct
                );
                ScIterator5Ptr it5_2= m_memoryCtx.Iterator5(
                ScType::NodeConst,
                ScType::EdgeUCommonConst,
                cycle[i],
                ScType::EdgeAccessConstPosPerm,
                inputGraphStruct
                );

                while (it5_1->Next())
                {
           
                auto iter=find(cycle.begin(),cycle.end(),it5_1->Get(2));
                if(iter!=cycle.end()) {
                    if(i==cycle.size()-1)
                    {

                        if(it5_1->Get(2)!=cycle[0] && it5_1->Get(2)!=cycle[i-1]) 
                        {
                               ScAddr hord=it5_1->Get(1);
                        
                            
                               if(result.size()!=0)
                               {
                               if(check(hord,result)) result.push_back(hord); 
                               }
                               else result.push_back(hord); 
                        
                        }
                         continue;
                    }
                    if(i==0)
                    {

                       if(it5_1->Get(2)!=cycle[i+1] && it5_1->Get(2)!=cycle[cycle.size()-1]) 
                       {
                           ScAddr hord=it5_1->Get(1);
                             
                               if(result.size()!=0)
                               {
                               if(check(hord,result)) result.push_back(hord); 
                               }
                               else result.push_back(hord); 
                        
                          
                       }
                       continue;
                    }

                    if(it5_1->Get(2)!=cycle[i+1] && it5_1->Get(2)!=cycle[i-1])
                    {
                              ScAddr hord=it5_1->Get(1);
                         
                               if(result.size()!=0)
                               {
                               if(check(hord,result)) result.push_back(hord); 
                               }
                               else result.push_back(hord); 
                        
                    } 
                    
                }
                }

                while (it5_2->Next())
                {
           
                auto iter=find(cycle.begin(),cycle.end(),it5_2->Get(0));
                if(iter!=cycle.end()) {
                    if(i==cycle.size()-1)
                    {

                        if(it5_2->Get(0)!=cycle[0] && it5_2->Get(0)!=cycle[i-1]) 
                        {
                               ScAddr hord=it5_1->Get(1);
                          
                               if(result.size()!=0)
                               {
                               if(check(hord,result)) result.push_back(hord); 
                               }
                               else result.push_back(hord); 
                        
                        }
                         continue;
                    }
                    if(i==0)
                    {

                       if(it5_2->Get(0)!=cycle[i+1] && it5_2->Get(0)!=cycle[cycle.size()-1]) 
                       {
                        ScAddr hord=it5_1->Get(1);
                              
                              if(result.size()!=0)
                               {
                               if(check(hord,result)) result.push_back(hord); 
                               }
                               else result.push_back(hord); 
                        
                          
                       }
                       continue;
                    }

                    if(it5_2->Get(0)!=cycle[i+1] && it5_2->Get(0)!=cycle[i-1])
                    {
                              ScAddr hord=it5_1->Get(1);
                            
                              if(result.size()!=0)
                               {
                               if(check(hord,result)) result.push_back(hord); 
                               }
                               else result.push_back(hord); 
                        
                        
                    } 
                    
                }
                }
            }
       
    }
  
    return result;
}
bool HordsAgent::check(ScAddr hord,ScAddrVector result)
{
  
        for(auto example:result)
            {
                if(hord==example) 
                 {
                 return false;
                 }
            }
   

        return true;
        
}

}
