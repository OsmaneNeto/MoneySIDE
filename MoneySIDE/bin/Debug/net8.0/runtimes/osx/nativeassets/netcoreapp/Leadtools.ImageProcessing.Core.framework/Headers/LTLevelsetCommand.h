// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLevelsetCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLevelsetCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger lambdaIn;
@property (nonatomic, assign) NSInteger lambdaOut;

- (instancetype)initWithLambdaIn:(NSInteger)lambdaIn lambdaOut:(NSInteger)lambdaOut NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
