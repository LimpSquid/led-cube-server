#include <net/routing/router.h>
#include <net/routing/router_node.h>
#include <net/routing/token_data.h>
#include <stdexcept>
#include <utility>

using namespace rest::net::routing;

router::router()
{

}

router::~router()
{

}

router_node &router::make_node(const std::string &url_expression)
{
    router_node new_node(url_expression);

    for(const router_node &node : nodes_) {
        if(node == new_node)
            throw std::invalid_argument("Url expression already specified for router");
    }
    return nodes_.emplace_back(std::move(new_node));
}