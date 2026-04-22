#include <string>
#include <vector>

#ifndef QUIZ_H
#define QUIZ_H



/*
* header file for Question class, sub classes TextQuestion, MultipleChoiceQuestion, TrueFalseQuestion, 
* which manages quiz behaviors and answers
* Owyn Lee, Anakin Schneider
*/


/**
 * So for the quiz system, we will use a vector of Question pointers to 
 * store the quiz questions, and each question will be an instance of a subclass of Question 
 * (TextQuestion, MultipleChoiceQuestion, TrueFalseQuestion). This way each 
 * question can have its own implementation of the checkAnswer function, which will allow us to
 * handle different types of questions in a flexible way. The Question class will have a virtual
 * checkAnswer function that will be overridden by each subclass to check the answer based on the question
 * type. The quiz system will then iterate through the vector of Question pointers, display each question,
 */







// Header file for Question class, which manages quiz questions and answers
class Question {
public:
    Question();

    //virtual check answer function, which will be overridden 
    //by the subclasses to check the answer based on the question type
    virtual bool checkAnswer(std::string input) = 0;

    virtual void displayQuestion();

     

private:
    //store value
    std::string questionText;
};

//class TextQuestion : public Question
class TextQuestion : public Question {
public:
    TextQuestion();

private:
    std::string correctAnswer;
};






//class MultipleChoiceQuestion : public Question
class MultipleChoiceQuestion : public Question {
public:
    MultipleChoiceQuestion();

private:
    std::vector<std::string> choices;
    int correctAnswerChoice;
};





//True false question class
class TrueFalseQuestion : public Question {
public:
    TrueFalseQuestion();

private:
    bool correctAnswer;
};




#endif