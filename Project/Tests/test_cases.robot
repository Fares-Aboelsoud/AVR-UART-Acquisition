*** Settings ***
Documentation      Embedded Systems project Test Cases

*** Variables ***
${BTN}    0
${LED}    0

*** Test Cases ***
Test Case 1: Button is pressed and holded for 20 seconds
    Set Suite Variable    ${BTN}    1
    # Button state didn't change while holding the button
    Should Be Equal As Integers    ${BTN}    1

Test Case 2: Typing "LED off" while LED is off
    Set Suite Variable    ${LED}    0
    # Nothing Happend
    Should Be Equal As Integers    ${LED}    0

Test Case 3: Typing a random word in serial monitor
    Set Suite Variable    ${LED}    0
    # System ignored it
    Should Be Equal As Integers    ${LED}    0

Test Case 4: Typing "LED on" while button is pressed
    Set Suite Variable    ${BTN}    1
    Set Suite Variable    ${LED}    1
    # No function affected the another
    Should Be Equal As Integers    ${LED}    1