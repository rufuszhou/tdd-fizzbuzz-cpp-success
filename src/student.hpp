#pragma once

#include <string>
#include <functional>

class Feature
{
public:
    Feature() : m_fired(false) {}
    virtual ~Feature() {}
    virtual void check(unsigned long id) = 0;
    std::string get_string(void) {
        return m_feature_string;
    }
    bool fired() {
        bool f = m_fired;
        m_fired = false;
        return f;
    }
protected:
    std::string m_feature_string;
    bool        m_fired;
};

class FeatureFizz : public Feature 
{
public:
    virtual void check(unsigned long id) {
        if ( id % 3 == 0 ) {
            m_fired = true;
            m_feature_string = "Fizz";
        }
    }
};

class FeatureBuzz : public Feature 
{
public:
    virtual void check(unsigned long id) {
        if ( id % 5 == 0 ) {
            m_fired = true;
            m_feature_string = "Buzz";
        }
    }
};

class FeatureBasic : public Feature 
{
public:
    virtual void check(unsigned long id) {
        m_fired = true;
        m_feature_string = std::to_string(id);
    }
};


class Student
{
public:
    Student(unsigned long id): m_id(id) {
        setup_features();
    }
    Student(const Student& s) = delete;
    Student& operator=(const Student& s) = delete;
    ~Student(){
        for (auto f: m_adv_features) {
            delete f;
        }
    }

    std::string to_string(void) {
        std::string str;
        bool        bAdvanced = false;
        for(auto f: m_adv_features) {
            f->check(m_id);
            if (f->fired()) {
                str += f->get_string();
                bAdvanced = true;
            }
        }
        if(!bAdvanced) {
            m_basic_feature.check(m_id);
            if(m_basic_feature.fired()) {
                str = m_basic_feature.get_string();
            }
        }
        return str;
    }

private:
    void setup_features() {
        m_adv_features.push_back(new FeatureFizz());
        m_adv_features.push_back(new FeatureBuzz());
    }

private:
    unsigned long         m_id;

    std::vector<Feature*> m_adv_features;
    FeatureBasic          m_basic_feature;
};