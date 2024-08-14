// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSegmentMatchingCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSegmentMatchingCommand : LTRasterCommand

@property (nonatomic, assign) LeadRect originalrect;
@property (nonatomic, assign) NSInteger fieldscount;
@property (nonatomic, assign) NSInteger *fieldsboundries;
@property (nonatomic, strong) NSData *headerByteInfo;
@property (nonatomic, assign, readonly) LeadRect headerarea;
@property (nonatomic, assign, readonly) double headerareaconfidence;

@end

NS_ASSUME_NONNULL_END
