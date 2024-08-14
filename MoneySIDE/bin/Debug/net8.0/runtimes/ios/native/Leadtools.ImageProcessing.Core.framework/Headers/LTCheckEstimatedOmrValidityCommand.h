// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCheckEstimatedOmrValidityCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCheckEstimatedOmrValidityCommand : LTRasterCommand

@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *zones; //LeadRect
@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *validZones;

@end

NS_ASSUME_NONNULL_END

