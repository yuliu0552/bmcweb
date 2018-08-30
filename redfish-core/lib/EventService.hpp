/*
// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/
#pragma once

#include "node.hpp"

namespace redfish {

class EventService : public Node {
 public:
  EventService(CrowApp& app) : Node(app, "/redfish/v1/EventService/") {
    Node::json["@odata.id"] = "/redfish/v1/EventService";
    Node::json["@odata.type"] = "#EventService.v1_0_3.EventService";
    Node::json["@odata.context"] =
        "/redfish/v1/$metadata#EventService.EventService";        
    Node::json["Id"] = "EventService";
    Node::json["Description"] = "Event Service";
    Node::json["Name"] = "Event Service";
    Node::json["ServiceEnabled"] = true;    
    Node::json["Status"]["Health"] = "OK";
    Node::json["Status"]["State"] = "Enabled";    
    Node::json["Subscriptions"]["@odata.id"] = "/redfish/v1/EventService/Subscriptions";   

    entityPrivileges = {
        {boost::beast::http::verb::get, {{"Login"}}},
        {boost::beast::http::verb::head, {{"Login"}}},
        {boost::beast::http::verb::patch, {{"ConfigureUsers"}}},
        {boost::beast::http::verb::put, {{"ConfigureUsers"}}},
        {boost::beast::http::verb::delete_, {{"ConfigureUsers"}}},
        {boost::beast::http::verb::post, {{"ConfigureUsers"}}}};
  }

 private:
  void doGet(crow::Response& res, const crow::Request& req,
             const std::vector<std::string>& params) override {
    res.jsonValue = Node::json;
    res.end();
  }
};

}  // namespace redfish
