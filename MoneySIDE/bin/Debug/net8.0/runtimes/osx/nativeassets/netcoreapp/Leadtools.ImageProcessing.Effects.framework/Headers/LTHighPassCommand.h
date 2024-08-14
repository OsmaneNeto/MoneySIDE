// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTHighPassCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTHighPassCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger radius;
@property (nonatomic, assign) NSUInteger opacity;

- (instancetype)initWithRadius:(NSUInteger)radius opacity:(NSUInteger)opacity NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
