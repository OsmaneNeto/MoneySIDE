// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTObjectInformationCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTObjectInformationCommand : LTRasterCommand

@property (nonatomic, assign, readonly) LeadPoint centerOfMass;
@property (nonatomic, assign, readonly) NSInteger angle;
@property (nonatomic, assign, readonly) NSUInteger roundness;
@property (nonatomic, assign)           BOOL weighted;

- (instancetype)initWithWeighted:(BOOL)weighted NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
