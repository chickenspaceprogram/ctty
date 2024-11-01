#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <stddef.h>
#include <string.h>

typedef struct al_data ArrayListData;


typedef struct array_list ArrayList;
/* 
"We have C++ at home"
C++ at home:
 */
struct array_list {
    ArrayListData data;

    // more methods aren't provided since they'd be annoying to implement and wouldn't be used here

    /**
     * Function name: ArrayList.get
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    void *(*get)(ArrayList *, size_t);

    /**
     * Function name: ArrayList.push
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    ArrayList *(*push)(ArrayList *, void *);

    /**
     * Function name: ArrayList.set
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    ArrayList *(*set)(ArrayList *, size_t, void *);

    /**
     * Function name: ArrayList.pop
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    ArrayList *(*pop)(ArrayList *);

    /**
     * Function name: ArrayList.clear
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    ArrayList *(*clear)(ArrayList *);

    /**
     * Function name: ArrayList.free
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    void (*free)(ArrayList *);

    /**
     * Function name: ArrayList.len
     * Date created: 31 Oct 2024
     * Date last modified: 31 Oct 2024
     * Description: 
     * Inputs: 
     * Outputs: 
     */
    size_t (*len)(ArrayList *);
};

ArrayList *newArrayList(size_t element_size);


#endif