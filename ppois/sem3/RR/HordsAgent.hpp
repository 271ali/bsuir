#pragma once
#include <sc-memory/kpm/sc_agent.hpp>
#include "keynodes/keynodes.hpp"
#include "HordsAgent.generated.hpp"
#include <vector>
using namespace std;
namespace exampleModule
{
  /*struct Hord
  {
    ScAddr node1;
    ScAddr node2;
    ScAddr edge;
  };*/
  using Cycle=std::vector<ScAddr>;
  using VisitedNodes=std::vector<ScAddr>;
  //using Hords=std::vector<Hord>;
  class HordsAgent:public ScAgent{
     SC_CLASS(Agent, Event(Keynodes::question_find_hords, ScEvent::Type::AddOutputEdge))
     SC_GENERATED_BODY()
     void answerConstructionSuccesfull( ScAddr const & inputGraphStruct,ScAddrVector & answerElements,ScAddrVector hords);
     void answerConstructionForUnchordal( ScAddr const & inputGraphStruct,ScAddrVector & answerElements);
     void answerConstructionForAcyclic( ScAddr const & inputGraphStruct,ScAddrVector & answerElements);
     void answerConstructionForOriented( ScAddr const & inputGraphStruct,ScAddrVector & answerElements);
     bool noOrientCheck(ScAddr const & inputGraphStruct);
     vector<Cycle> findCycles(ScAddr const & inputGraphStruct);
     void dfs(ScAddr startNode,ScAddr currentNode,VisitedNodes vn,vector<Cycle>& result,Cycle cycle,ScAddr const & inputGraphStruct);
     ScAddrVector getHords(vector<Cycle> cycles,ScAddr const & inputGraphStruct);
     bool check(ScAddr hord,ScAddrVector result);
  };
 
}
