// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
//

#pragma once

#include <iostream>
#include <sstream>

#include <ql/exercise.hpp>
#include <ql/time/date.hpp>
#include <ql/patterns/singleton.hpp>
#include <ql/settings.hpp>
#include <ql/instruments/swaption.hpp>
#include <ql/indexes/ibor/euribor.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/daycounters/thirty360.hpp>

#include <qlCppCli.hpp>
#include <managedCalendar/managedCalendar.hpp>
#include <threads/writerThread.hpp>
#include <threads/pricingThread.hpp>
#include <threads/workThread.hpp>

// TODO: faites référence ici aux en-têtes supplémentaires nécessaires au programme
