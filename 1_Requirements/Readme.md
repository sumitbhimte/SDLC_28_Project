# Requirements

## Introduction

A fully functional password maneger which involves operation to save the account credentials, retrive account credentials, generate passwords, delete account credentials. This project can be used by anyone in day to day life.

## Research

A [study](https://www.vice.com/en/article/zmjvm9/hundreds-of-thousands-of-people-are-using-passwords-that-have-already-been-hacked-google-says) by google confirmed internet users need to stop same password for multiple website unless they are keen on having their data hijacked. But using different passwords for different websites creates another problem. A [study](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3515440/) from 2012 shows relation between passwords usage and human memory limitations. regarding the frequency with which participants reported memory difficulties, a large number of participants reported forgetting or mixing up passwords (72%) in the present sample. Thus concluding all these findings a system which can be used to save and retrive password securely So that users don't need to remeber all this information is needed..

## Cost and Features and Timeline

As far as the project is well built and all the requirements met the cost can be varied according to the market.

## Defining Our System

The system mainly involves two operation modes. They modifying master username or password and user credential operations. All the operation are subdivided into operations where user can choose the operation he wants and can perform accordingly.

# SWOT Analysis

[Here](https://github.com/AnkitDhiman2/SDLC_28_Project/blob/main/1_Requirements/TexPAd%20password%20maneger-1.png) is a brief analysis on Strengths, Weaknesses, Opportunities and Threats.

# 4 W's and 1 H

### WHO

The project can be used almost by all. All the users accros the world who use different social media accounts have credentials to save can use the program to save their credentials. At the end, user satisfaction is the goal of the project.

### WHAT

Program can save account credential of the user securely. User can also use the program to generate passwords.

### WHEN

The project can be used in day to day life. So that user don't have to remeber all the passwords for so many website or organisations

### WHERE

In all the domains it can be used. As the project is portable and user-friendly, it can be easily implemented on the mobile systems and finance companies. It should overcome all the drawbacks of the Old existing system and most important of all meet the user requirements.

### HOW

System design is a solution for “HOW TO” approach to the creation of a new system. It translates system requirements into ways by which they can be made operational. It is a translational from a user oriented document to a document oriented programmers. For that, it provides the understanding and procedural details necessary for the implementation. Here UML diagrams are used to supplement the working of the new system. The system thus made should be reliable, durable and above all should have least possible maintenance costs.

# Detail requirements

## System Requirements

| ID    | Description                                     | Status      |
| ----- | ----------------------------------------------- | ----------- |
| HR_01 | System shall be able to run on Windows 10/Linux | In progress |
| HR_02 | System shall be able to on minimum RAM(512MB)   | In progress |

## High Level Requirements:

| ID    | Description                                                                            | Status      |
| ----- | -------------------------------------------------------------------------------------- | ----------- |
| HR_01 | User shall use single master account to access all his credentials                     | In progress |
| HR_02 | User shall be able to create master account with specific username and password format | In progress |
| HR_03 | User shall be able to manage master Account                                            | In progress |
| HR_04 | User shall be able to manage user Credentials                                          | In progress |
| HR_05 | System shall use encryption techniques                                                 | In progress |

## Low level Requirements:

| ID    | Description                                                            | Type  | Status      |
| ----- | ---------------------------------------------------------------------- | ----- | ----------- |
| LR_01 | Function to check if String contain special characrers                 | HR_02 | In progress |
| LR_02 | Function to check if string contain numbers                            | HR_02 | In progress |
| LR_03 | Function to check if string contain upper case letter                  | HR_02 | In progress |
| LR_04 | Function to check if string contain lower case letter                  | HR_02 | In progress |
| LR_05 | Function to check Format of password                                   | HR_02 | In progress |
| LR_06 | Function to check Format of username                                   | HR_02 | In progress |
|       |                                                                        |       |             |
| LR_07 | Function to create master user                                         | HR_03 | In progress |
| LR_08 | Function to delete master user                                         | HR_03 | In progress |
| LR_09 | Function to modify master account username                             | HR_03 | In progress |
| LR_10 | Function to modify master account pasword                              | HR_03 | In progress |
|       |                                                                        |       |             |
| LR_11 | Function to check if master account exist                              | HR_01 | In progress |
| LR_12 | Function to verify master Account                                      | HR_01 | In Progress |
|       |                                                                        |       |             |
| LR_13 | Function to add new credential                                         | HR_04 | In progress |
| LR_14 | Function to delete credential                                          | HR_04 | In progress |
| LR_15 | Function to serach credential                                          | HR_04 | In progress |
| LR_16 | Function to modify credential username                                 | HR_04 | In progress |
| LR_17 | Function to modify credential organisation                             | HR_04 | In progress |
| LR_18 | Function to modify credential password                                 | HR_04 | In progress |
| LR_19 | Function to show all credentials                                       | HR_04 | In progress |
| LR_20 | Function to sort given user credentials according to organisation name | HR_04 | In progress |
| LR_21 | Function to check if credential exist or not                           | HR_04 | In progress |
|       |                                                                        |       |             |
| LR_22 | Function to encrypt credential file                                    | HR_05 | In progress |
| LR_23 | Function to decrypt credential file                                    | HR_05 | In progress |
| LR_24 | Function to create hash of master account and username                 | HR_05 | In progress |
