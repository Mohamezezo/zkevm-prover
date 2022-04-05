#include "smt_action_context.hpp"
#include "scalar.hpp"

void SmtActionContext::init (const SmtAction &action)
{

    if (action.bIsSet)
    {
        level = action.setResult.siblings.size();
        key[0] = action.setResult.key[0];
        key[1] = action.setResult.key[1];
        key[2] = action.setResult.key[2];
        key[3] = action.setResult.key[3];
        siblings = action.setResult.siblings;
    }
    else
    {
        level = action.getResult.siblings.size();
        key[0] = action.getResult.key[0];
        key[1] = action.getResult.key[1];
        key[2] = action.getResult.key[2];
        key[3] = action.getResult.key[3];
        siblings = action.getResult.siblings;
    }

    // Initial value of rKey is key
    rKey[0] = key[0];
    rKey[1] = key[1];
    rKey[2] = key[2];
    rKey[3] = key[3];
    FiniteField fr;

#ifdef LOG_STORAGE_EXECUTOR
    cout << "SmtActionContext::init() key=" << fea2string(fr, key) << endl;
#endif

    // Generate bits vector
    bits.clear();
    for (uint64_t i=0; i<level; i++)
    {
        uint64_t keyNumber = i%4; // 0, 1, 2, 3, 0, 1, 2, 3...
        uint64_t bit = rKey[keyNumber]&1;
        bits.push_back(bit);
        rKey[keyNumber] /= 2;
        //cout << "SmtActionContext::init() rKey=" << fea2string(fr, rKey) << endl;
    }

    // Print bits vector content
#ifdef LOG_STORAGE_EXECUTOR
    cout << "SmtActionContext::init() ";
    for (uint64_t i=0; i<bits.size(); i++)
    {
        cout << "bits[" << i << "]=" << bits[i] << " ";
    }
    cout << endl;
#endif

    // Print rKey content
#ifdef LOG_STORAGE_EXECUTOR
    cout << "SmtActionContext::init() rKey=" << fea2string(fr, rKey) << endl;
#endif

    // Set current level
    currentLevel = bits.size();
}