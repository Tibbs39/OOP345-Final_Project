// Name: Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email: kyue3@myseneca.ca
// Date of completion: November 28, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <vector>
#include <iostream>
#include <fstream>
#include "Task.h"
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& str, std::vector<Task*>& tasks, std::vector<CustomerOrder>& custOrders) {
    std::ifstream file(str);
    
    if (!file)
		throw std::string("Unable to open [") + str + "] file.";

    Utilities util;
    size_t next_pos = 0;
    bool more = true;

    std::string record;
    std::string task;
    std::string next;

    bool isFirst = true;

    while(!file.eof()) {
        std::getline(file, record);

        if (record.empty())
            throw std::string("*** Empty Record in [") + str + "] ***";

        task = util.extractToken(record, next_pos, more);
        if (more)
            next = util.extractToken(record, next_pos, more);

        if (!next.empty()) {
            for (size_t i = 0; i < tasks.size(); ++i) {
                if (tasks[i]->getName() == task) {
                    // save position of first task
                    if (isFirst) {
                        m_firstTask = i;
                        isFirst = !isFirst;
                    }

                    for (size_t j = 0; j < tasks.size(); ++j) {
                        if (tasks[j]->getName() == next) {
                            tasks[i]->setNextTask(*tasks[j]);
                            break;
                        }
                    }
                    break;
                }
            }
        }

        // reset
        next_pos = 0;
        more = true;
        task.clear();
        next.clear();
    }

    for (size_t i = 0; i < custOrders.size(); ++i) 
        ToBeFilled.push_back(std::move(custOrders[i]));
    custOrders.erase(custOrders.begin(),custOrders.end());

    AssemblyLine = tasks;
}

bool LineManager::run(std::ostream& os) {
    bool done = true;
    
    if (!ToBeFilled.empty()) {
        *AssemblyLine[m_firstTask] += std::move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }

    for (size_t i = 0; i < AssemblyLine.size(); ++i) {
        // try / catch: There might not be available inventory
        try {
            AssemblyLine[i]->runProcess(os);
        }
        catch (std::string err) {
            std::cout << std::endl << err << std::endl;
            throw std::string("Not enough inventory available");
        }
    }

    CustomerOrder buffer; // remove any completed orders
    for (size_t i = 0; i < AssemblyLine.size(); ++i) {
        if (AssemblyLine[i]->getCompleted(buffer))
            Completed.push_back(std::move(buffer));
    }

    // check if assemblyline is complete
    for (size_t i = 0; i < AssemblyLine.size(); ++i) {
        // if any of them return true, there's still at least one order in the assembly line
        if (AssemblyLine[i]->moveTask()) {
            done = false; 
            
        }
    }

    return done;
}

void LineManager::displayCompleted(std::ostream& os) const {
    if (!Completed.empty())
        for (size_t i = 0; i < Completed.size(); ++i) 
            Completed[i].display(os);
}

void LineManager::validateTasks() const {
    if (!AssemblyLine.empty())
        for (size_t i = 0; i < AssemblyLine.size(); ++i)
            AssemblyLine[i]->validate(std::cout);
}