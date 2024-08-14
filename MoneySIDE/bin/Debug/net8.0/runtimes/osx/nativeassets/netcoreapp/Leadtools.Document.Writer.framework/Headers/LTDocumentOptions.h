// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDocumentOptions.h
//  Leadtools.Document.Writer
//

#import <Leadtools.Document.Writer/LTDocumentFormat.h>

typedef NS_ENUM(NSInteger, LTDocumentWriterPageRestriction) {
    LTDocumentWriterPageRestrictionDefault,
    LTDocumentWriterPageRestrictionRelaxed
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDocumentOptions : NSObject <NSCopying, NSCoding> // ABSTRACT

@property (nonatomic, assign, readonly) LTDocumentFormat format;

@property (nonatomic, assign)           LTDocumentWriterPageRestriction pageRestriction;

@property (nonatomic, assign)           double emptyPageWidth;
@property (nonatomic, assign)           double emptyPageHeight;

@property (nonatomic, assign)           NSInteger emptyPageResolution;
@property (nonatomic, assign)           NSInteger documentResolution;

@property (nonatomic, assign)           BOOL maintainAspectRatio;

@end

NS_ASSUME_NONNULL_END
