# AWS SDK for Ruby Version 3 code examples
## Overview
The code examples in this topic show you how to use the AWS SDK for Ruby Version 3 with AWS. 

The AWS SDK for Ruby Version 3 provides a Ruby API for AWS infrastructure services. Using the SDK, you can build applications on top of Amazon S3, Amazon EC2, Amazon DynamoDB, and more.

## Types of code examples
* **Single-service actions** - Code examples that show you how to call individual service functions.

* **Single-service scenarios** - Code examples that show you how to accomplish a specific task by calling multiple functions within the same service.

* **Cross-service examples** - Sample applications that work across multiple AWS services.

### Finding code examples

Single-service actions and scenarios are organized by AWS service in the 
[example_code folder](example_code). A README in each folder lists and describes how 
to run the examples.

There are currently no cross-service examples for the AWS SDK for Ruby.
To request a cross-service example, create an issue in the 
[AWS SDK Code Examples](https://github.com/awsdocs/aws-doc-sdk-examples/) repo.

## ⚠️ Important
* Running this code might result in charges to your AWS account. 
* Running the tests might result in charges to your AWS account.
*  We recommend that you grant your code least privilege. At most, grant only the minimum permissions required to perform the task. For more information, see [Grant least privilege](https://docs.aws.amazon.com/IAM/latest/UserGuide/best-practices.html#grant-least-privilege). 
* This code is not tested in every AWS Region. For more information, see [AWS Regional Services](https://aws.amazon.com/about-aws/global-infrastructure/regional-product-services).

## Get started

To begin, you must [set up an AWS account](../README.md#prerequisites-for-all-aws-sdks) and [configure credentials locally](../README.md#configuring-the-aws-sdks).

To resolve Ruby-specific dependencies, you must start a command line session and navigate to this directory.

First, verify your version of Ruby is at 3.1 using the following command:
```bash
ruby -v
```

Next, execute the following commands to resolve [Gemfile](Gemfile) dependencies:
```bash
gem install bundler
bundle install
```

## Tests
**Note**: Running the tests might result in charges to your AWS account.

All tests use RSpec, and you can find them in the `spec` folder for each example. Please check the README for each service or cross-service example for any additional requirements to run tests.

### Unit tests
**Note**: Running the tests might result in charges to your AWS account.

The unit tests in this module use stubbed responses from AWS SDK for Ruby. 
This means that when the unit tests are run, requests are not sent to AWS, 
mocked responses are returned, and no charges are incurred on your account.

Run unit tests in the folder for each service or cross-service example at a command 
prompt by including the `~integ` tag.

```
rspec --tag ~integ
```

### Integration tests
**Note**: Running the tests might result in charges to your AWS account.

The integration tests in this module make actual requests to AWS. This means that when the integration tests are run, they can create and destroy resources in your account. These tests might also incur charges. Proceed with caution.

Run integration tests in the folder for each service or cross-service example at a 
command prompt by including the `integ` tag.

```
rspec --tag integ
```

## Additional resources
 
* [AWS SDK for Ruby Developer Guide](https://docs.aws.amazon.com/sdk-for-ruby/v3/developer-guide/welcome.html)
* [AWS SDK for Ruby API Reference](https://docs.aws.amazon.com/sdk-for-ruby/v3/api/)


Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved. SPDX-License-Identifier: Apache-2.0
