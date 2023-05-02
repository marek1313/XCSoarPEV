// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The XCSoar Project

#include "FAIGoalTaskFactory.hpp"
#include "Constraints.hpp"


static constexpr TaskFactoryConstraints fai_goal_constraints = {
  true, //task_scored
  true,  //fai finish
  false,  //homogenous tps
  false, //is closed
  false, //score start at pev
  0,  //maximum height loss (start - finish)
  false, //arm start required
  2, 2,  //min points, max points
};

FAIGoalTaskFactory::FAIGoalTaskFactory(OrderedTask& _task,
                               const TaskBehaviour &tb):
  FAITaskFactory(fai_goal_constraints, _task, tb)
{
}
