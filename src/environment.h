#pragma once
#include <csignal>
#include <chrono>
#include <functional>
#include <random>

#include "tinyGraphDB.h"

/**
 * Global things needed by the algorithm (random generator, signal reference, etc.).
 */
class Environment
{
 public:
    typedef std::minstd_rand RandGen;
    typedef std::chrono::high_resolution_clock Clock;

    RandGen randGen;
    TinyGraphDB db;
    double cutoff;
    static bool found_cut;
    std::chrono::time_point<Clock> constructedTime;
    std::chrono::time_point<Clock> startTime;

    Environment (unsigned int seed, double seconds) :
        randGen(seed),
        cutoff(seconds),
        constructedTime(Clock::now()),
        startTime(constructedTime) {
        //fprintf(stderr, "Initializing small graph database...\n");
        db.initialize();
    }

    bool interrupt() {
        return (std::chrono::duration<double>(Clock::now() - startTime).count()) >= cutoff && found_cut;
    }
};
