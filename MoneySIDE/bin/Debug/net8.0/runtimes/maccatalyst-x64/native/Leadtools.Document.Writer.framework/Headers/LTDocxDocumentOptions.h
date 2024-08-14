// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDocxDocumentOptions.h
//  Leadtools.Document.Writer
//

#import <Leadtools.Document.Writer/LTDocumentOptions.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDocxDocumentOptions : LTDocumentOptions <NSCopying, NSCoding>

@property (nonatomic, assign) LTDocumentTextMode textMode;
@property (nonatomic, assign) LTDocumentDropObjects dropObjects;

@end

NS_ASSUME_NONNULL_END
