//!
//! Datatypes for MCMC.
//!
//! \file infer/mcmctypes.hpp
//! \author Lachlan McCalman
//! \date December 2013
//! \license Affero General Public License version 3 or later
//! \copyright (c) 2014, NICTA
//!

#pragma once

#include <Eigen/Core>

namespace stateline
{
  namespace mcmc
  {
    //! Used for recording swapping of chains.
    //!
    enum class SwapType
    {
      //! No swap was attempted.
      NoAttempt,

      //! A swap was accepted.
      Accept,

      //! A swap was rejected.
      Reject
    };

    //! Used to represent a state in a Markov Chain.
    //!
    struct State
    {
      //! The actual sample that the state represents.
      Eigen::VectorXd sample;

      //! The energy (negative log likelihood) of the state.
      double energy;

      //! The inverse temperature of the chain when this state was recorded.
      double beta;

      //! Whether this state was an accepted proposal state or a copy of the previous state.
      bool accepted;

      //! The type of swap that occurred when this state was recorded.
      SwapType swapType;
    };

    //! Type representing proposal acceptance functions.
    using PropAcceptFn = std::function<bool(const State&, const State&, double)>;

    //! Type representing swap acceptance functions.
    using SwapAcceptFn = std::function<bool(const State&, const State&, double, double)>;

  }
}
