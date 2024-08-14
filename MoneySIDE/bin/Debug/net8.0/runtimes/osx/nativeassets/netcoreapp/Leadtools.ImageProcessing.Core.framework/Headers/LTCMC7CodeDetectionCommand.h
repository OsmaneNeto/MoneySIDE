// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCMC7CodeDetectionCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>
#import "LTMICRCodeDetectionCommand.h"

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCMC7CodeDetectionCommand : LTRasterCommand

@property (nonatomic, assign, readonly) LeadRect cMC7Zone;
@property(nonatomic, assign)            NSInteger confidence;
@property(nonatomic, assign)            LTMICRCodeFoundIssue foundIssues;

@end

NS_ASSUME_NONNULL_END
