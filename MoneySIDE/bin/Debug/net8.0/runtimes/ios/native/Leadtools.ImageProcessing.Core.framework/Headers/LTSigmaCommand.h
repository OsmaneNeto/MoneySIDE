// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSigmaCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSigmaCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger dimension;
@property (nonatomic, assign) NSUInteger sigma;
@property (nonatomic, retain) NSNumber*  threshold;
@property (nonatomic, assign) BOOL      outline;

- (instancetype)initWithDimension:(NSUInteger)dimension sigma:(NSUInteger)sigma threshold:(NSNumber*)threshold outline:(BOOL)outline NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
