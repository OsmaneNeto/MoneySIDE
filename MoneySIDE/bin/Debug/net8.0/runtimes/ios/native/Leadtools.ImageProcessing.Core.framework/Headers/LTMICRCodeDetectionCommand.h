// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMICRCodeDetectionCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTMICRCodeFoundIssue) {
   LTMICRCodeFoundIssueNone = 0,
   LTMICRCodeFoundIssueOverlappedCharacters = 0x0001,
   LTMICRCodeFoundIssueBlurImage = 0x0002,
   LTMICRCodeFoundIssueIncorrectFieldsCount = 0x0004,
   LTMICRCodeFoundIssueLargeFieldsDistance = 0x0008,
   LTMICRCodeFoundIssueMissingChar = 0x0010,
   //LTMICRCodeFoundIssueIncorrectPatterns = (int)ltimgcor.MICR_DETECTION_INCORRECT_PATTERNS,
   LTMICRCodeFoundIssueNoisy = 0x0020,
   LTMICRCodeFoundIssueAttachedToSigniture = 0x0040
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTMICRCodeDetectionCommand : LTRasterCommand

@property (nonatomic, assign)           LeadRect searchingZone;
@property (nonatomic, assign, readonly) LeadRect micrZone;
@property(nonatomic, assign)            NSInteger confidence;
@property(nonatomic, assign)            LTMICRCodeFoundIssue issues;

- (instancetype)initWithSearchingZone:(LeadRect)searchingZone NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
