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
  
  if (noOrientCheck(inputGraphStruct)==false)
  {
    SC_LOG_ERROR("Graph is oriented");
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
    return SC_RESULT_ERROR_INVALID_PARAMS;
  }
   vector<Cycle> cycles=findCycles(inputGraphStruct)
   if (cycles.isEmpty())
  {
    SC_LOG_ERROR("No cycles in graph");
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
    return SC_RESULT_ERROR_INVALID_PARAMS;
  }
    vector<Hord> hords=getHords(cycles); 
     if (hords.isEmpty())
  {
    SC_LOG_ERROR("No hords in graph");
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
    return SC_RESULT_ERROR_INVALID_PARAMS;
  }
  ScAddrVector answerElements;
  answerConstruction(inputGraphStruct,answerElements,hords);
  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, answerElements, true);
}

void HordsAgent::answerConstruction( ScAddr const & inputGraphStruct,ScAddrVector & answerElements,vector<Hord> hords)
{
    ScAddr HordClass = m_memoryCtx.CreateNode(ScType::NodeConstClass);  
    ScAddrVector hordEdges;
    for(auto hord:hords)
    {
        hordEdge=m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, HordClass, hord);
        hordEdges.push_back(hordEdge);
    }
    graphAndHordsNode=m_memoryCtx.CreateNode(ScType::NodeConstTuple);
    graphAndHordsEdge = m_memoryCtx.CreateEdge(ScType::EdgeDCommonConst, inputGraphStruct,graphAndHordsNode);
    hordsNrel=m_memoryCtx.CreateNode(ScType::NodeConstNorole);
    relation = m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, hordsNrel, graphAndHordsEdge);

  answerElements.insert(answerElements.end(), {HordClass, hordEdges,hords,graphAndHordsNode,graphAndHordsEdge,hordsNrel,relation});
}
bool HordsAgent::noOrientCheck(ScAddr const & inputGraphStruct)
{

    SC_LOG_ERROR("Check is beginning");
    ScAddrVector graphNodes;
    ScIterator3Ptr it3_0=m_memoryCtx.Iterator3(
    inputGraphStruct,
    ScType::EdgeAccessConstPosPerm,
    ScType::NodeConst);
    while (it3_0->Next())
    {
        graphNodes.push_back( it3_0->Get(2) );
    }
    SC_LOG_ERROR("GraphNodes are defined");
    for(auto node:graphNodes)
    {
           ScIterator3Ptr it3_1=m_memoryCtx.Iterator3(
            node,
            ScType::EdgeAccessConstPosPerm,
            ScType::NodeConst);
             while (it3_1->Next())
             {
                ScIterator3Ptr it3_2=m_memoryCtx.Iterator3(
                it3_1->Get(1)
                ScType::EdgeAccessConstPosPerm,
                node);
                  while (it3_0->Next())
                  {
                    if(it3_1->Get(1)!=it3_1->Get(2)) return false;
                    SC_LOG_ERROR("Chek is completing");
                  }
            }
        
    }
    return true;
   
}
vector<Cycle> HordsAgent::findCycles(ScAddr const & inputGraphStruct)
{
    SC_LOG_ERROR("Start cycles finding");
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
    SC_LOG_ERROR("GraphNodes are defined");
    for (auto node : graphNodes)
    {
        Cycle cycle;
        VisitedNodes vn;
        vector<Cycle> cycles;
        dfs(node,node,vn,cycles,cycle)ж
        result.insert(result.end(),cycles.begin(),cycles.end());
    }
    SC_LOG_ERROR("Finish cycles finding");
    return result;
}

void HordsAgent::dfs(ScAddr startNode,ScAddr currentNode,VisitedNodes vn,vector<Cycle> result,Cycle cycle)
{
    SC_LOG_ERROR("DFS");
    if(startNode==currentNode && !visitedNodes.empty())
    {
       result.push_back(cycle);
       return;
    }
   auto iter=find(visitedNodes.begin(),visitedNodes.end(),currentNode);
   if(iter!=visitedNodes.end()) return;
   visitedNodes.push_back(currentNode);
   cycle.push_back(currentNode);
   ScAddrVector currentNeighbourNodes;
   ScIterator3Ptr it3=m_memoryCtx.Iterator3(
   currentNode,
   ScType::EdgeAccessConstPosPerm,
   ScType::NodeConst NodeConst);
   while (it3->Next())
    {
      currentNeighbourNodes.push_back( it3->Get(2) )
    }
    for(auto node:currentNeighbourNodes)
    {
        if(cycle.size()>1 && cycle[cycle.size()-2]==node) continue;
        dfs(startNode,node,vn,result,cycle);
    }
}

vector<Hord> HordsAgent::getHords(vector<Cycle> cycles)
{
     vector<Hord> result;
    SC_LOG_ERROR("Start hords finding");
    for(auto cycle:cycles)
    {
        if(cycle.size()>3)
        {
            int lastStartIndex = cycle.size() / 2 + cycles.size() % 2;
             SC_LOG_ERROR("Cycle exploring");
            for(int i=0;i<lastStartIndex;i++){
             
                cIterator3Ptr it3=m_memoryCtx.Iterator3(
                cycle[i],
                ScType::EdgeAccessConstPosPerm,
                ScType::NodeConst);
                while (it3->Next())
                {
                 if(it3->Get(2)!=cycle[i+1] && it3->Get(2)!=cycle[i-1])
                 {
                    Hord hord;
                    hord.node1=cycle[i];
                    hord.node2=it3->Get(2);
                    hord.edge=it3->Get(1);
                    result.push_back(hord);
                 }
                }
            }
        }
        else continue; 
    }
}

}