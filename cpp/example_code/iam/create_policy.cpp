/*
   Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
   SPDX-License-Identifier: Apache-2.0
*/

#include <aws/core/Aws.h>
#include <aws/iam/IAMClient.h>
#include <aws/iam/model/CreatePolicyRequest.h>
#include <aws/iam/model/CreatePolicyResult.h>
#include <iostream>
#include "iam_samples.h"

/**
 * Before running this C++ code example, set up your development environment, including your credentials.
 *
 * For more information, see the following documentation topic:
 *
 * https://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/getting-started.html
 *
 * Purpose
 *
 * Creates a fixed policy with name.
 *
 */

namespace AwsDoc {
    namespace IAM {
        static Aws::String BuildSamplePolicyDocument(const Aws::String& rsrc_arn);
    } // IAM
} // AwsDoc

// snippet-start:[iam.cpp.create_policy.code]
//! Creates a fixed policy with name.
/*!
  \sa createPolicy()
  \param policyName: The policy name.
  \param rsrcArn: The Amazon Resource Name.
  \param clientConfig Aws client configuration.
  \return bool: Successful completion.
*/

bool AwsDoc::IAM::createPolicy(const Aws::String& policyName,
                               const Aws::String& rsrcArn,
                                    const Aws::Client::ClientConfiguration &clientConfig)
{
    Aws::IAM::IAMClient iam;

    Aws::IAM::Model::CreatePolicyRequest request;
    request.SetPolicyName(policyName);
    request.SetPolicyDocument(BuildSamplePolicyDocument(rsrcArn));

    auto outcome = iam.CreatePolicy(request);
    if (!outcome.IsSuccess())
    {
        std::cerr << "Error creating policy " << policyName << ": " <<
                  outcome.GetError().GetMessage() << std::endl;
    }
    else
    {
        std::cout << "Successfully created policy " << policyName <<
                  std::endl;
    }

    return outcome.IsSuccess();
}
// snippet-end:[iam.cpp.create_policy.code]

//snippet-start:[iam.cpp.build_policy.code]
Aws::String AwsDoc::IAM::BuildSamplePolicyDocument(const Aws::String& rsrc_arn)
{
    std::stringstream stringStream;
    stringStream << "{"
    << "  \"Version\": \"2012-10-17\","
            << "  \"Statement\": ["
            << "    {"
            << "        \"Effect\": \"Allow\","
            << "        \"Action\": \"logs:CreateLogGroup\","
            << "        \"Resource\": \""
            << rsrc_arn
            << "\""
            << "    },"
            << "    {"
            << "        \"Effect\": \"Allow\","
            << "        \"Action\": ["
            << "            \"dynamodb:DeleteItem\","
            << "            \"dynamodb:GetItem\","
            << "            \"dynamodb:PutItem\","
            << "            \"dynamodb:Scan\","
            << "            \"dynamodb:UpdateItem\""
            << "       ],"
            << "       \"Resource\": \""
            << rsrc_arn
            << "\""
            << "    }"
            << "   ]"
            << "}";

    return stringStream.str();
}
//snippet-end:[iam.cpp.build_policy.code]

/*
 *
 *  main function
 *
 * Usage: run_create_policy <policy_name> <resource_arn>'
 *
 */

#ifndef TESTING_BUILD
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: create_policy <policy_name> <resource_arn>" <<
            std::endl;
        return 1;
    }

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        Aws::Client::ClientConfiguration clientConfig;
        // Optional: Set to the AWS Region in which the bucket was created (overrides config file).
        // clientConfig.region = "us-east-1";
        Aws::String policyName(argv[1]);
        Aws::String rsrcArn(argv[2]);

        AwsDoc::IAM::createPolicy(policyName, rsrcArn, clientConfig);
    }
    Aws::ShutdownAPI(options);
    return 0;
}
#endif // TESTING_BUILD

