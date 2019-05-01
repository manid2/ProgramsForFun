/*
 * test_producer.cpp
 *
 *  Created on: 01-Mar-2018
 *      Author: mani
 */

#include "test_precomp.h"
#include "producer.h"
#include "consumer.h"

using namespace PFF;

namespace {

class ProducerMock : public Producer {
 public:
  MOCK_METHOD1(getNameVirt, std::string(const std::string& name));
};

TEST(Producer, GetNameVirt) {
  const std::string name = "test_gmock_name";
  std::string val = "in test code";

  ProducerMock mock;
  Consumer client(&mock);
  client.fCallNameVirt();

  EXPECT_CALL(mock, getNameVirt(name)).WillOnce(::testing::Return(val));
}

}  // namespace
