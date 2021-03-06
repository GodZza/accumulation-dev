#include "server.h"
#include "server_private.h"

void server_start(struct server_s* self,
                  logic_on_enter_handle enter_callback,
                  logic_on_close_handle close_callback,
                  logic_on_recved_handle    recved_callback,
                  logic_on_cansend_handle cansend_callback,
                  logic_on_sendfinish_handle  sendfinish_callback)
{
    (self->start_callback)(self, enter_callback, close_callback, recved_callback, cansend_callback, sendfinish_callback);
}

void server_pool(struct server_s* self, int timeout)
{
    (self->poll_callback)(self, timeout);
}

void server_stop(struct server_s* self)
{
    (self->stop_callback)(self);
}

void server_close(struct server_s* self, void* handle)
{
    (self->closesession_callback)(self, handle);
}

bool server_register(struct server_s* self, void* ud, int fd)
{
    return (self->register_callback)(self, ud, fd);
}

int server_send(struct server_s* self, void* handle, const char* data, int len)
{
    return (self->send_callback)(self, handle, data, len);
}

int server_sendv(struct server_s* self, void* handle, const char* datas[], const int* lens, int num)
{
    return (self->sendv_callback)(self, handle, datas, lens, num);
}

void* server_getext(struct server_s* self)
{
    return self->ext;
}

