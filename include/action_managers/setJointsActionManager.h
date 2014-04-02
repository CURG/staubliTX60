#ifndef SetJointsAction_H
#define SetJointsAction_H

#include "action_managers/staubliControlActionManager.h"
#include "staubli_tx60/SetJointsAction.h"

class SetJointsActionManager: public StaubliControlActionManager<staubli_tx60::SetJointsAction>
{
   public:
      SetJointsActionManager(const std::string & actionName);
      bool polling( const std::vector<double> &j1 );
      virtual bool sendGoal() ;
      virtual void publishFeedback();
};

#endif /* SetJointsAction_H */
