#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "thread.h"
#include "wqueue.h"

class WorkItem
{
    string m_message;
    
public:
    WorkItem(const char* message): m_message(message)
    {
        
    }
    
    ~WorkItem() {}
    
    const char* getMessage()
    {
        return m_message.c_str();
    }

};

class ConsumerThread : public Thread
{
    wqueue<WorkItem*>& m_queue;
    
public:
    ConsumerThread(wqueue<WorkItem*>& queue) : m_queue(queue)
    {
        
    }
    void* run() {
        // Remove 1 item at a time and process it. Blocks if no items are
        // available to process.
        for (int i = 0; ;i++) {
            printf("thread %lu, loop %d - waiting for item...\n",
                   (long unsigned int)self(), i);
            
            WorkItem* item = (WorkItem*)m_queue.remove();
            
            printf("thread %lu, loop %d - got one item\n",
                   (long unsigned int)self(), i);
            
            printf("thread %lu, loop %d - item: message - %s, number - %d\n",
                   (long unsigned int)self(), i, item->getMessage());
            delete item;
        }
        return NULL;
    }
};
