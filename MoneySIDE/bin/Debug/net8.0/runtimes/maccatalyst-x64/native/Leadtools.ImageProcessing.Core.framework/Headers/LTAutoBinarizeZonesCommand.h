// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAutoBinarizeZonesCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAutoBinarizeZonesCommand : LTRasterCommand

@property (nonatomic, strong, nullable) NSArray<NSValue *> *zones;  // LeadRect

@end

NS_ASSUME_NONNULL_END
