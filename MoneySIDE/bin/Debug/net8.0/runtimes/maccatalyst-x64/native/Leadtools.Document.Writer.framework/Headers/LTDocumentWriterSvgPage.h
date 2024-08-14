// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDocumentWriterSvgPage.h
//  Leadtools.Document.Writer
//

#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTSvgDocument.h>

#import <Leadtools.Document.Writer/LTDocumentWriterPage.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDocumentWriterSvgPage : LTDocumentWriterPage <NSCopying>

@property (nonatomic, strong) id<ISvgDocument> svgDocument;

@property (nonatomic, strong) LTRasterImage *image;

@property (nonatomic, assign) double width;
@property (nonatomic, assign) double height;

@end
