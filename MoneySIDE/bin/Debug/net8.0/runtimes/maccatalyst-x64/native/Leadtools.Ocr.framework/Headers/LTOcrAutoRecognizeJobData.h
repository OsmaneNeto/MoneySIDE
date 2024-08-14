// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrAutoRecognizeJobData.h
//  Leadtools.Ocr
//

#import <Leadtools.Document.Writer/LTDocumentFormat.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrAutoRecognizeJobData : NSObject

@property (nonatomic, copy)             NSString *imageFileName;
@property (nonatomic, copy)             NSString *documentFileName;
@property (nonatomic, copy, nullable)   NSString *zonesFileName;
@property (nonatomic, copy, nullable)   NSString *jobName;

@property (nonatomic, assign)           LTDocumentFormat format;

@property (nonatomic, assign)           NSInteger firstPageNumber;
@property (nonatomic, assign)           NSInteger lastPageNumber;
@property (nonatomic, assign)           NSInteger imagePageCount;

@property (nonatomic, strong, nullable) NSObject *userData;


- (instancetype)initWithImageFile:(NSString *)fileName format:(LTDocumentFormat)format documentFile:(NSString *)documentFile;
- (instancetype)initWithImageFile:(NSString *)fileName zonesFile:(nullable NSString *)zonesFile format:(LTDocumentFormat)format documentFile:(NSString *)documentFile;
- (instancetype)initWithImageFile:(NSString *)fileName firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage format:(LTDocumentFormat)format documentFile:(NSString *)documentFile;
- (instancetype)initWithImageFile:(NSString *)fileName firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage zonesFile:(nullable NSString *)zonesFile format:(LTDocumentFormat)format documentFile:(NSString *)documentFile NS_DESIGNATED_INITIALIZER;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
