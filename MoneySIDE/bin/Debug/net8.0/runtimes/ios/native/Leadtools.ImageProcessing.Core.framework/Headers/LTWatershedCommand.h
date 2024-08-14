// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTWatershedCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTWatershedCommand : LTRasterCommand

@property (nonatomic, strong) NSArray<NSArray<NSValue *> *> *pointsArray; //LeadPoint

- (instancetype)initWithPointsArray:(NSArray<NSArray<NSValue *> *> *)pointsArray /*LeadPoint*/ NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
