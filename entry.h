#ifndef PO_PROJEKT_ENTRY_H
#define PO_PROJEKT_ENTRY_H

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class Entry{
private:
    std::string title;
    float rating;
    int lenght;
    std::vector <std::string> tags;
    float fitness;
public:
    Entry(std::string name);
    ~Entry(void);
    std::string showTitle();
    float showRating();
    int showLength();
    std::vector <std::string> showTags();
    float showFitness();
    virtual void showStatistics(void);
    void addTag(std::string tag);
    void setLenght(int tempLenght);
    void setRating(float tempRating);
    void removeTag(std::string tag);

};


#endif //PO_PROJEKT_ENTRY_H
