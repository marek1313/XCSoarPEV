// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The XCSoar Project

#include "FAIORTaskFactory.hpp"
#include "Constraints.hpp"


static constexpr TaskFactoryConstraints fai_or_constraints = {
  true, //task_scored
  true,  //fai finish
  false,  //homogenous tps
  true, //is closed
  false, //score start at pev
  0,  //maximum height loss (start - finish)
  false, //arm start required
  3, 3,  //min points, max points
};

FAIORTaskFactory::FAIORTaskFactory(OrderedTask& _task,
                                   const TaskBehaviour &tb)
  :FAITaskFactory(fai_or_constraints, _task, tb)
{
}
