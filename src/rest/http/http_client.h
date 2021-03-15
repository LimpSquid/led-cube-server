#pragma once

#include <http/types.h>
#include <net/tcp_client.h>
#include <net/routing/router.h>

namespace rest::http
{

class http_client : public rest::net::tcp_client
{
public:
    /**
     * @brief Construct a new http_client object
     * @param management The management associated to this client
     * @param socket The socket for this client
     */
    http_client(rest::net::tcp_client_management &management, socket_type &&socket);
    
    /**
     * @brief Destroy the http_client object
     */
    virtual ~http_client() override;

private:
    virtual void state_changed(const client_state &state) override;
    void async_read();
    void http_read(boost::beast::error_code error);

    rest::net::routing::router::pointer router_;
    request_type request_;
    buffer_type buffer_;
};

}