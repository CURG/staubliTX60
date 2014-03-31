#ifndef StaubliControlActionManager_H
#define StaubliControlActionManager_H

#include "action_managers/staubliActionManager.h"
#include "actionlib/server/simple_action_server.h"

template <class ActionType, class FeedbackType, class ResultType,  class GoalType>
class StaubliControlActionManager : public StaubliActionManager
{

protected:
    actionlib::SimpleActionServer<ActionType> as_;
    ResultType mResult;
    FeedbackType mFeedback_;
    std::vector<double> mGoal;

    /*@brief abortHard - Abort the current job and shut down the node.
    *
    *
    */
    bool abortHard();


    virtual void cancelAction();

    /*@brief pollRobot - Test if the robot has reached its goal
    *
    *@param goal_joints - Vector of goal positions
    *
    *@returns whether the goal is still in progress
    */
    bool pollRobot( const std::vector<double> &goal_joints) ;


public:
    StaubliControlActionManager(const std::string & actionName, const std::string & actionTopic) : StaubliActionManager (actionName),
        as_(nh_, actionTopic, boost::bind(&StaubliControlActionManager::newGoalCallback, this, _1))
    {
    }

    //virtual void sendGoal() = 0;


    /*@brief - Callback for recieving a new goal
    * Should cancel any existing actions that are trying to control the robot
    * and send the new goal to the robot
    */
    void newGoalCallback(const typename GoalType::ConstPtr &goal);


    /* @brief runFeedback - Poll the goal to make sure it is still running and legal, send any feedback that needs sending
    * to the actions' clients
    */
    void runFeedback();

};

#endif /* StaubliControlActionManager_H */
