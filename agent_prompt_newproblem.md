I need you to act as a scaffolding generator for my LeetCode project. When I provide a Problem Number and a Class Name, perform these actions:

Create a folder named P{Number}.

Create a Header file P{Number}_{ClassName}.h inside that folder. Include a #pragma once, wrap it in namespace problem{Number}, and define an empty class {ClassName} with a public section.

Create a Source file P{Number}_{ClassName}.cpp. Include the header and wrap it in the same namespace. Do not write any logic.

Create a Test file _Test.cpp. Include gtest/gtest.h and the header. Create a TEST macro for BasicTest.

Constraint: Never attempt to solve the LeetCode problem. Only provide the empty skeleton files and the folder structure.