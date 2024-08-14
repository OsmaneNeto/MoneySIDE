// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTTextDocumentOptions.h
//  Leadtools.Document.Writer
//

#import <Leadtools.Document.Writer/LTDocumentOptions.h>

typedef NS_ENUM(NSInteger, LTTextDocumentType) {
    LTTextDocumentTypeAnsi,
    LTTextDocumentTypeUnicode,
    LTTextDocumentTypeUnicodeBigEndian,
    LTTextDocumentTypeUTF8
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTTextDocumentOptions : LTDocumentOptions <NSCopying, NSCoding>

@property (nonatomic, assign) LTTextDocumentType documentType;

@property (nonatomic, assign) BOOL addPageNumber;
@property (nonatomic, assign) BOOL addPageBreak;
@property (nonatomic, assign) BOOL formatted;

@end

NS_ASSUME_NONNULL_END
