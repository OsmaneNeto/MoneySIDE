// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrAutoRecognizeManagerJobError.h
//  Leadtools.Ocr
//

typedef NS_ENUM(NSInteger, LTOcrAutoRecognizeManagerJobOperation) {
    LTOcrAutoRecognizeManagerJobOperationOther,
    LTOcrAutoRecognizeManagerJobOperationCreateDocument,
    LTOcrAutoRecognizeManagerJobOperationPrepareDocument,
    LTOcrAutoRecognizeManagerJobOperationLoadPage,
    LTOcrAutoRecognizeManagerJobOperationPreprocessPage,
    LTOcrAutoRecognizeManagerJobOperationZonePage,
    LTOcrAutoRecognizeManagerJobOperationRecognizePage,
    LTOcrAutoRecognizeManagerJobOperationSavePage,
    LTOcrAutoRecognizeManagerJobOperationAppendLtd,
    LTOcrAutoRecognizeManagerJobOperationSaveDocument,
    LTOcrAutoRecognizeManagerJobOperationConvertDocument
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrAutoRecognizeManagerJobError : NSObject

@property (nonatomic, assign) NSInteger imagePageNumber;
@property (nonatomic, assign) LTOcrAutoRecognizeManagerJobOperation operation;
@property (nonatomic, strong) NSError *error;

- (instancetype)initWithPageNumber:(NSInteger)imagePageNumber operation:(LTOcrAutoRecognizeManagerJobOperation)operation error:(NSError *)error;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
