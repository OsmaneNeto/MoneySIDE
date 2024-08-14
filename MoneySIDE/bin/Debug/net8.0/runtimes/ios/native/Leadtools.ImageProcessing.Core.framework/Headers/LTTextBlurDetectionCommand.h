// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTTextBlurDetectionCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTTextBlurDetectionCommand : LTRasterCommand

@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *inFocusBlocks; //LeadRect
@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *outOfFocusBlocks; //LeadRect
@property (nonatomic, assign, readonly) LeadRect combinedTextBlocks;

@end
