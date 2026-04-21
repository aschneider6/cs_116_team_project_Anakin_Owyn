#include <iostream>
#include <vector>

/*
* header file for Quiz class, sub classes TextQuestion, MultipleChoiceQuestion, TrueFalseQuestion, 
* which manages quiz behaviors and answers
* Owyn Lee, Anakin Schneider
*/

//have not fully finished this yet, but I will add more to it later. I just wanted to get the basic structure down for now.





// Header file for Quiz class, which manages quiz questions and answers
class Quiz {
public:
    Quiz();

     

private:
    //store value
};

//class TextQuestion : public Quiz 
class TextQuestion : public Quiz {
public:
    TextQuestion();

private:
    std::string correctAnswer;
};






//class MultipleChoiceQuestion : public Quiz
class MultipleChoiceQuestion : public Quiz {
public:
    MultipleChoiceQuestion();

private:
    std::vector<std::string> choices;
    int correctAnswerChoice;
};





//True false question class
class TrueFalseQuestion : public Quiz {
public:
    TrueFalseQuestion();

private:
    bool correctAnswer;
};


