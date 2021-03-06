#include <stdio.h>
#include "double_link.h"
#include "event.h"

void my_event_handler(struct event_object_s* root, struct event_object_s* source, void* data, const void* arg)
{
        int int_arg = *(int*)arg;
        printf("my_event_handler, int arg : %d\n", int_arg);
}

void my_event_handler1(struct event_object_s* root, struct event_object_s* source, void* data, const void* arg)
{
        int int_arg = *(int*)arg;
        printf("my_event_handler1, int arg : %d\n", int_arg);
}

enum event_type
{
    event_1,
};

int main()
{
    struct event_object_s* oa = event_object_create();
    struct event_object_s* ob = event_object_create();
    struct event_object_s* oc = event_object_create();
    
    int arg = 10;
    
    /*  为oa对象添加一个(感兴趣)事件处理器  */
    event_object_insert_handler(oa, event_1, my_event_handler, NULL);
    //event_object_remove_handler(oa, event_1, my_event_handler, NULL);

    /*  为oc对象添加一个(感兴趣)事件处理器  */
    event_object_insert_handler(oc, event_1, my_event_handler1, NULL);

    //event_object_remove_handler(oc, event_1, my_event_handler1, NULL);
    /*  为ob对象添加观察者oa和oc    */
    event_object_insert_observer(ob, event_1, oa);
    event_object_insert_observer(ob, event_1, oc);
    //object_remove_observer(ob, event_1, oa);
    
    /*  通知ob对象触发了一个事件, 其(对此事件感兴趣)观察者会处理此事件   */
    event_object_nofify(ob, event_1, &arg);
    
    /*  调用自身事件处理器   */
    event_object_handler(oa, oa, event_1, &arg);
    
    return 0;
}
