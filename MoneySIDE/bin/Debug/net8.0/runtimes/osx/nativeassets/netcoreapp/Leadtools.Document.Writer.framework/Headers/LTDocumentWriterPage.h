// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDocumentWriterPage.h
//  Leadtools.Document.Writer
//

typedef NS_ENUM(NSInteger, LTDocumentWriterPageType) {
    LTDocumentWriterPageTypeEmf,
    LTDocumentWriterPageTypeSvg,
    LTDocumentWriterPageTypeRaster,
    LTDocumentWriterPageTypeEmpty
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDocumentWriterPage : NSObject <NSCopying> // ABSTRACT

@property (nonatomic, assign, readonly) LTDocumentWriterPageType type;

@end

NS_ASSUME_NONNULL_END
