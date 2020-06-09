UserInput::UserInput(){
    tempUserInput = " ";
}
UserInput::UserInput(char input){
    tempUserInput = input;
}
        
        /* Logic */
void UserInput::performAction(){
    switch(tempUserInput){
    case 'a':
    //damageCalculation();
    break;
    case 'r':
    //runAway();
    break;
    default:
    break;
    }
}
