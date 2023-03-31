set(SEMANTIC_ANALYSIS_INCLUDE_DIR ${SEMANTIC_ANALYSIS_DIR}/include)
set(SEMANTIC_ANALYSIS_SOURCE_DIR ${SEMANTIC_ANALYSIS_DIR}/src)

add_library(FermiSemanticAnalysis 
    ${SEMANTIC_ANALYSIS_SOURCE_DIR}/Type.cpp
    ${SEMANTIC_ANALYSIS_SOURCE_DIR}/FermiModule.cpp
    ${SEMANTIC_ANALYSIS_SOURCE_DIR}/ASTGenerator.cpp
    ${SEMANTIC_ANALYSIS_SOURCE_DIR}/ASTNodes/ExpressionASTNode.cpp
    ${SEMANTIC_ANALYSIS_SOURCE_DIR}/ASTNodes/StatementASTNode.cpp
    )

    target_include_directories(FermiSemanticAnalysis PRIVATE 
    ${SEMANTIC_ANALYSIS_INCLUDE_DIR}
    ${PARSER_DIR}/include)