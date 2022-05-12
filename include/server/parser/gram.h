/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_BASE_YY_SRC_BACKEND_PARSER_GRAM_H_INCLUDED
# define YY_BASE_YY_SRC_BACKEND_PARSER_GRAM_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int base_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    FCONST = 259,                  /* FCONST  */
    SCONST = 260,                  /* SCONST  */
    BCONST = 261,                  /* BCONST  */
    XCONST = 262,                  /* XCONST  */
    Op = 263,                      /* Op  */
    ICONST = 264,                  /* ICONST  */
    PARAM = 265,                   /* PARAM  */
    TYPECAST = 266,                /* TYPECAST  */
    DOT_DOT = 267,                 /* DOT_DOT  */
    COLON_EQUALS = 268,            /* COLON_EQUALS  */
    EQUALS_GREATER = 269,          /* EQUALS_GREATER  */
    LESS_EQUALS = 270,             /* LESS_EQUALS  */
    GREATER_EQUALS = 271,          /* GREATER_EQUALS  */
    NOT_EQUALS = 272,              /* NOT_EQUALS  */
    ABORT_P = 273,                 /* ABORT_P  */
    ABSOLUTE_P = 274,              /* ABSOLUTE_P  */
    ACCESS = 275,                  /* ACCESS  */
    ACTION = 276,                  /* ACTION  */
    ADD_P = 277,                   /* ADD_P  */
    ADMIN = 278,                   /* ADMIN  */
    AFTER = 279,                   /* AFTER  */
    AGGREGATE = 280,               /* AGGREGATE  */
    ALL = 281,                     /* ALL  */
    ALSO = 282,                    /* ALSO  */
    ALTER = 283,                   /* ALTER  */
    ALWAYS = 284,                  /* ALWAYS  */
    ANALYSE = 285,                 /* ANALYSE  */
    ANALYZE = 286,                 /* ANALYZE  */
    AND = 287,                     /* AND  */
    ANY = 288,                     /* ANY  */
    ARRAY = 289,                   /* ARRAY  */
    AS = 290,                      /* AS  */
    ASC = 291,                     /* ASC  */
    ASSERTION = 292,               /* ASSERTION  */
    ASSIGNMENT = 293,              /* ASSIGNMENT  */
    ASYMMETRIC = 294,              /* ASYMMETRIC  */
    AT = 295,                      /* AT  */
    ATTACH = 296,                  /* ATTACH  */
    ATTRIBUTE = 297,               /* ATTRIBUTE  */
    AUTHORIZATION = 298,           /* AUTHORIZATION  */
    BACKWARD = 299,                /* BACKWARD  */
    BEFORE = 300,                  /* BEFORE  */
    BEGIN_P = 301,                 /* BEGIN_P  */
    BETWEEN = 302,                 /* BETWEEN  */
    BIGINT = 303,                  /* BIGINT  */
    BINARY = 304,                  /* BINARY  */
    BIT = 305,                     /* BIT  */
    BOOLEAN_P = 306,               /* BOOLEAN_P  */
    BOTH = 307,                    /* BOTH  */
    BY = 308,                      /* BY  */
    CACHE = 309,                   /* CACHE  */
    CALLED = 310,                  /* CALLED  */
    CASCADE = 311,                 /* CASCADE  */
    CASCADED = 312,                /* CASCADED  */
    CASE = 313,                    /* CASE  */
    CAST = 314,                    /* CAST  */
    CATALOG_P = 315,               /* CATALOG_P  */
    CHAIN = 316,                   /* CHAIN  */
    CHAR_P = 317,                  /* CHAR_P  */
    CHARACTER = 318,               /* CHARACTER  */
    CHARACTERISTICS = 319,         /* CHARACTERISTICS  */
    CHECK = 320,                   /* CHECK  */
    CHECKPOINT = 321,              /* CHECKPOINT  */
    CLASS = 322,                   /* CLASS  */
    CLOSE = 323,                   /* CLOSE  */
    CLUSTER = 324,                 /* CLUSTER  */
    COALESCE = 325,                /* COALESCE  */
    COLLATE = 326,                 /* COLLATE  */
    COLLATION = 327,               /* COLLATION  */
    COLUMN = 328,                  /* COLUMN  */
    COLUMNS = 329,                 /* COLUMNS  */
    COMMENT = 330,                 /* COMMENT  */
    COMMENTS = 331,                /* COMMENTS  */
    COMMIT = 332,                  /* COMMIT  */
    COMMITTED = 333,               /* COMMITTED  */
    CONCURRENTLY = 334,            /* CONCURRENTLY  */
    CONFIGURATION = 335,           /* CONFIGURATION  */
    CONFLICT = 336,                /* CONFLICT  */
    CONNECTION = 337,              /* CONNECTION  */
    CONSTRAINT = 338,              /* CONSTRAINT  */
    CONSTRAINTS = 339,             /* CONSTRAINTS  */
    CONTENT_P = 340,               /* CONTENT_P  */
    CONTINUE_P = 341,              /* CONTINUE_P  */
    CONVERSION_P = 342,            /* CONVERSION_P  */
    COPY = 343,                    /* COPY  */
    COST = 344,                    /* COST  */
    CREATE = 345,                  /* CREATE  */
    CROSS = 346,                   /* CROSS  */
    CSV = 347,                     /* CSV  */
    CUBE = 348,                    /* CUBE  */
    CURRENT_P = 349,               /* CURRENT_P  */
    CURRENT_CATALOG = 350,         /* CURRENT_CATALOG  */
    CURRENT_DATE = 351,            /* CURRENT_DATE  */
    CURRENT_ROLE = 352,            /* CURRENT_ROLE  */
    CURRENT_SCHEMA = 353,          /* CURRENT_SCHEMA  */
    CURRENT_TIME = 354,            /* CURRENT_TIME  */
    CURRENT_TIMESTAMP = 355,       /* CURRENT_TIMESTAMP  */
    CURRENT_USER = 356,            /* CURRENT_USER  */
    CURSOR = 357,                  /* CURSOR  */
    CYCLE = 358,                   /* CYCLE  */
    DATA_P = 359,                  /* DATA_P  */
    DATABASE = 360,                /* DATABASE  */
    DAY_P = 361,                   /* DAY_P  */
    DEALLOCATE = 362,              /* DEALLOCATE  */
    DEC = 363,                     /* DEC  */
    DECIMAL_P = 364,               /* DECIMAL_P  */
    DECLARE = 365,                 /* DECLARE  */
    DEFAULT = 366,                 /* DEFAULT  */
    DEFAULTS = 367,                /* DEFAULTS  */
    DEFERRABLE = 368,              /* DEFERRABLE  */
    DEFERRED = 369,                /* DEFERRED  */
    DEFINER = 370,                 /* DEFINER  */
    DELETE_P = 371,                /* DELETE_P  */
    DELIMITER = 372,               /* DELIMITER  */
    DELIMITERS = 373,              /* DELIMITERS  */
    DEPENDS = 374,                 /* DEPENDS  */
    DESC = 375,                    /* DESC  */
    DETACH = 376,                  /* DETACH  */
    DICTIONARY = 377,              /* DICTIONARY  */
    DISABLE_P = 378,               /* DISABLE_P  */
    DISCARD = 379,                 /* DISCARD  */
    DISTINCT = 380,                /* DISTINCT  */
    DO = 381,                      /* DO  */
    DOCUMENT_P = 382,              /* DOCUMENT_P  */
    DOMAIN_P = 383,                /* DOMAIN_P  */
    DOUBLE_P = 384,                /* DOUBLE_P  */
    DROP = 385,                    /* DROP  */
    EACH = 386,                    /* EACH  */
    ELSE = 387,                    /* ELSE  */
    ENABLE_P = 388,                /* ENABLE_P  */
    ENCODING = 389,                /* ENCODING  */
    ENCRYPTED = 390,               /* ENCRYPTED  */
    END_P = 391,                   /* END_P  */
    ENUM_P = 392,                  /* ENUM_P  */
    ESCAPE = 393,                  /* ESCAPE  */
    EVENT = 394,                   /* EVENT  */
    EXCEPT = 395,                  /* EXCEPT  */
    EXCLUDE = 396,                 /* EXCLUDE  */
    EXCLUDING = 397,               /* EXCLUDING  */
    EXCLUSIVE = 398,               /* EXCLUSIVE  */
    EXECUTE = 399,                 /* EXECUTE  */
    EXISTS = 400,                  /* EXISTS  */
    EXPLAIN = 401,                 /* EXPLAIN  */
    EXTENSION = 402,               /* EXTENSION  */
    EXTERNAL = 403,                /* EXTERNAL  */
    EXTRACT = 404,                 /* EXTRACT  */
    FALSE_P = 405,                 /* FALSE_P  */
    FAMILY = 406,                  /* FAMILY  */
    FETCH = 407,                   /* FETCH  */
    FILTER = 408,                  /* FILTER  */
    FIRST_P = 409,                 /* FIRST_P  */
    FLOAT_P = 410,                 /* FLOAT_P  */
    FOLLOWING = 411,               /* FOLLOWING  */
    FOR = 412,                     /* FOR  */
    FORCE = 413,                   /* FORCE  */
    FOREIGN = 414,                 /* FOREIGN  */
    FORWARD = 415,                 /* FORWARD  */
    FREEZE = 416,                  /* FREEZE  */
    FROM = 417,                    /* FROM  */
    FULL = 418,                    /* FULL  */
    FUNCTION = 419,                /* FUNCTION  */
    FUNCTIONS = 420,               /* FUNCTIONS  */
    GENERATED = 421,               /* GENERATED  */
    GLOBAL = 422,                  /* GLOBAL  */
    GRANT = 423,                   /* GRANT  */
    GRANTED = 424,                 /* GRANTED  */
    GREATEST = 425,                /* GREATEST  */
    GROUP_P = 426,                 /* GROUP_P  */
    GROUPING = 427,                /* GROUPING  */
    HANDLER = 428,                 /* HANDLER  */
    HAVING = 429,                  /* HAVING  */
    HEADER_P = 430,                /* HEADER_P  */
    HOLD = 431,                    /* HOLD  */
    HOUR_P = 432,                  /* HOUR_P  */
    IDENTITY_P = 433,              /* IDENTITY_P  */
    IF_P = 434,                    /* IF_P  */
    ILIKE = 435,                   /* ILIKE  */
    IMMEDIATE = 436,               /* IMMEDIATE  */
    IMMUTABLE = 437,               /* IMMUTABLE  */
    IMPLICIT_P = 438,              /* IMPLICIT_P  */
    IMPORT_P = 439,                /* IMPORT_P  */
    IN_P = 440,                    /* IN_P  */
    INCLUDING = 441,               /* INCLUDING  */
    INCREMENT = 442,               /* INCREMENT  */
    INDEX = 443,                   /* INDEX  */
    INDEXES = 444,                 /* INDEXES  */
    INHERIT = 445,                 /* INHERIT  */
    INHERITS = 446,                /* INHERITS  */
    INITIALLY = 447,               /* INITIALLY  */
    INLINE_P = 448,                /* INLINE_P  */
    INNER_P = 449,                 /* INNER_P  */
    INOUT = 450,                   /* INOUT  */
    INPUT_P = 451,                 /* INPUT_P  */
    INSENSITIVE = 452,             /* INSENSITIVE  */
    INSERT = 453,                  /* INSERT  */
    INSTEAD = 454,                 /* INSTEAD  */
    INT_P = 455,                   /* INT_P  */
    INTEGER = 456,                 /* INTEGER  */
    INTERSECT = 457,               /* INTERSECT  */
    INTERVAL = 458,                /* INTERVAL  */
    INTO = 459,                    /* INTO  */
    INVOKER = 460,                 /* INVOKER  */
    IS = 461,                      /* IS  */
    ISNULL = 462,                  /* ISNULL  */
    ISOLATION = 463,               /* ISOLATION  */
    JOIN = 464,                    /* JOIN  */
    KEY = 465,                     /* KEY  */
    LABEL = 466,                   /* LABEL  */
    LANGUAGE = 467,                /* LANGUAGE  */
    LARGE_P = 468,                 /* LARGE_P  */
    LAST_P = 469,                  /* LAST_P  */
    LATERAL_P = 470,               /* LATERAL_P  */
    LEADING = 471,                 /* LEADING  */
    LEAKPROOF = 472,               /* LEAKPROOF  */
    LEAST = 473,                   /* LEAST  */
    LEFT = 474,                    /* LEFT  */
    LEVEL = 475,                   /* LEVEL  */
    LIKE = 476,                    /* LIKE  */
    LIMIT = 477,                   /* LIMIT  */
    LISTEN = 478,                  /* LISTEN  */
    LOAD = 479,                    /* LOAD  */
    LOCAL = 480,                   /* LOCAL  */
    LOCALTIME = 481,               /* LOCALTIME  */
    LOCALTIMESTAMP = 482,          /* LOCALTIMESTAMP  */
    LOCATION = 483,                /* LOCATION  */
    LOCK_P = 484,                  /* LOCK_P  */
    LOCKED = 485,                  /* LOCKED  */
    LOGGED = 486,                  /* LOGGED  */
    MAPPING = 487,                 /* MAPPING  */
    MATCH = 488,                   /* MATCH  */
    MATERIALIZED = 489,            /* MATERIALIZED  */
    MAXVALUE = 490,                /* MAXVALUE  */
    METHOD = 491,                  /* METHOD  */
    MINUTE_P = 492,                /* MINUTE_P  */
    MINVALUE = 493,                /* MINVALUE  */
    MODE = 494,                    /* MODE  */
    MONTH_P = 495,                 /* MONTH_P  */
    MOVE = 496,                    /* MOVE  */
    NAME_P = 497,                  /* NAME_P  */
    NAMES = 498,                   /* NAMES  */
    NATIONAL = 499,                /* NATIONAL  */
    NATURAL = 500,                 /* NATURAL  */
    NCHAR = 501,                   /* NCHAR  */
    NEW = 502,                     /* NEW  */
    NEXT = 503,                    /* NEXT  */
    NO = 504,                      /* NO  */
    NONE = 505,                    /* NONE  */
    NOT = 506,                     /* NOT  */
    NOTHING = 507,                 /* NOTHING  */
    NOTIFY = 508,                  /* NOTIFY  */
    NOTNULL = 509,                 /* NOTNULL  */
    NOWAIT = 510,                  /* NOWAIT  */
    NULL_P = 511,                  /* NULL_P  */
    NULLIF = 512,                  /* NULLIF  */
    NULLS_P = 513,                 /* NULLS_P  */
    NUMERIC = 514,                 /* NUMERIC  */
    OBJECT_P = 515,                /* OBJECT_P  */
    OF = 516,                      /* OF  */
    OFF = 517,                     /* OFF  */
    OFFSET = 518,                  /* OFFSET  */
    OIDS = 519,                    /* OIDS  */
    OLD = 520,                     /* OLD  */
    ON = 521,                      /* ON  */
    ONLY = 522,                    /* ONLY  */
    OPERATOR = 523,                /* OPERATOR  */
    OPTION = 524,                  /* OPTION  */
    OPTIONS = 525,                 /* OPTIONS  */
    OR = 526,                      /* OR  */
    ORDER = 527,                   /* ORDER  */
    ORDINALITY = 528,              /* ORDINALITY  */
    OUT_P = 529,                   /* OUT_P  */
    OUTER_P = 530,                 /* OUTER_P  */
    OVER = 531,                    /* OVER  */
    OVERLAPS = 532,                /* OVERLAPS  */
    OVERLAY = 533,                 /* OVERLAY  */
    OVERRIDING = 534,              /* OVERRIDING  */
    OWNED = 535,                   /* OWNED  */
    OWNER = 536,                   /* OWNER  */
    PARALLEL = 537,                /* PARALLEL  */
    PARSER = 538,                  /* PARSER  */
    PARTIAL = 539,                 /* PARTIAL  */
    PARTITION = 540,               /* PARTITION  */
    PASSING = 541,                 /* PASSING  */
    PASSWORD = 542,                /* PASSWORD  */
    PLACING = 543,                 /* PLACING  */
    PLANS = 544,                   /* PLANS  */
    POLICY = 545,                  /* POLICY  */
    POSITION = 546,                /* POSITION  */
    PRECEDING = 547,               /* PRECEDING  */
    PRECISION = 548,               /* PRECISION  */
    PRESERVE = 549,                /* PRESERVE  */
    PREPARE = 550,                 /* PREPARE  */
    PREPARED = 551,                /* PREPARED  */
    PRIMARY = 552,                 /* PRIMARY  */
    PRIOR = 553,                   /* PRIOR  */
    PRIVILEGES = 554,              /* PRIVILEGES  */
    PROCEDURAL = 555,              /* PROCEDURAL  */
    PROCEDURE = 556,               /* PROCEDURE  */
    PROGRAM = 557,                 /* PROGRAM  */
    PUBLICATION = 558,             /* PUBLICATION  */
    QUOTE = 559,                   /* QUOTE  */
    RANGE = 560,                   /* RANGE  */
    READ = 561,                    /* READ  */
    REAL = 562,                    /* REAL  */
    REASSIGN = 563,                /* REASSIGN  */
    RECHECK = 564,                 /* RECHECK  */
    RECURSIVE = 565,               /* RECURSIVE  */
    REF = 566,                     /* REF  */
    REFERENCES = 567,              /* REFERENCES  */
    REFERENCING = 568,             /* REFERENCING  */
    REFRESH = 569,                 /* REFRESH  */
    REINDEX = 570,                 /* REINDEX  */
    RELATIVE_P = 571,              /* RELATIVE_P  */
    RELEASE = 572,                 /* RELEASE  */
    RENAME = 573,                  /* RENAME  */
    REPEATABLE = 574,              /* REPEATABLE  */
    REPLACE = 575,                 /* REPLACE  */
    REPLICA = 576,                 /* REPLICA  */
    RESET = 577,                   /* RESET  */
    RESTART = 578,                 /* RESTART  */
    RESTRICT = 579,                /* RESTRICT  */
    RETURNING = 580,               /* RETURNING  */
    RETURNS = 581,                 /* RETURNS  */
    REVOKE = 582,                  /* REVOKE  */
    RIGHT = 583,                   /* RIGHT  */
    ROLE = 584,                    /* ROLE  */
    ROLLBACK = 585,                /* ROLLBACK  */
    ROLLUP = 586,                  /* ROLLUP  */
    ROW = 587,                     /* ROW  */
    ROWS = 588,                    /* ROWS  */
    RULE = 589,                    /* RULE  */
    SAVEPOINT = 590,               /* SAVEPOINT  */
    SCHEMA = 591,                  /* SCHEMA  */
    SCHEMAS = 592,                 /* SCHEMAS  */
    SCROLL = 593,                  /* SCROLL  */
    SEARCH = 594,                  /* SEARCH  */
    SECOND_P = 595,                /* SECOND_P  */
    SECURITY = 596,                /* SECURITY  */
    SELECT = 597,                  /* SELECT  */
    SEQUENCE = 598,                /* SEQUENCE  */
    SEQUENCES = 599,               /* SEQUENCES  */
    SERIALIZABLE = 600,            /* SERIALIZABLE  */
    SERVER = 601,                  /* SERVER  */
    SESSION = 602,                 /* SESSION  */
    SESSION_USER = 603,            /* SESSION_USER  */
    SET = 604,                     /* SET  */
    SETS = 605,                    /* SETS  */
    SETOF = 606,                   /* SETOF  */
    SHARE = 607,                   /* SHARE  */
    SHOW = 608,                    /* SHOW  */
    SIMILAR = 609,                 /* SIMILAR  */
    SIMPLE = 610,                  /* SIMPLE  */
    SKIP = 611,                    /* SKIP  */
    SMALLINT = 612,                /* SMALLINT  */
    SNAPSHOT = 613,                /* SNAPSHOT  */
    SOME = 614,                    /* SOME  */
    SQL_P = 615,                   /* SQL_P  */
    STABLE = 616,                  /* STABLE  */
    STANDALONE_P = 617,            /* STANDALONE_P  */
    START = 618,                   /* START  */
    STATEMENT = 619,               /* STATEMENT  */
    STATISTICS = 620,              /* STATISTICS  */
    STDIN = 621,                   /* STDIN  */
    STDOUT = 622,                  /* STDOUT  */
    STORAGE = 623,                 /* STORAGE  */
    STRICT_P = 624,                /* STRICT_P  */
    STRIP_P = 625,                 /* STRIP_P  */
    SUBSCRIPTION = 626,            /* SUBSCRIPTION  */
    SUBSTRING = 627,               /* SUBSTRING  */
    SYMMETRIC = 628,               /* SYMMETRIC  */
    SYSID = 629,                   /* SYSID  */
    SYSTEM_P = 630,                /* SYSTEM_P  */
    TABLE = 631,                   /* TABLE  */
    TABLES = 632,                  /* TABLES  */
    TABLESAMPLE = 633,             /* TABLESAMPLE  */
    TABLESPACE = 634,              /* TABLESPACE  */
    TEMP = 635,                    /* TEMP  */
    TEMPLATE = 636,                /* TEMPLATE  */
    TEMPORARY = 637,               /* TEMPORARY  */
    TEXT_P = 638,                  /* TEXT_P  */
    THEN = 639,                    /* THEN  */
    TIME = 640,                    /* TIME  */
    TIMESTAMP = 641,               /* TIMESTAMP  */
    TO = 642,                      /* TO  */
    TRAILING = 643,                /* TRAILING  */
    TRANSACTION = 644,             /* TRANSACTION  */
    TRANSFORM = 645,               /* TRANSFORM  */
    TREAT = 646,                   /* TREAT  */
    TRIGGER = 647,                 /* TRIGGER  */
    TRIM = 648,                    /* TRIM  */
    TRUE_P = 649,                  /* TRUE_P  */
    TRUNCATE = 650,                /* TRUNCATE  */
    TRUSTED = 651,                 /* TRUSTED  */
    TYPE_P = 652,                  /* TYPE_P  */
    TYPES_P = 653,                 /* TYPES_P  */
    UNBOUNDED = 654,               /* UNBOUNDED  */
    UNCOMMITTED = 655,             /* UNCOMMITTED  */
    UNENCRYPTED = 656,             /* UNENCRYPTED  */
    UNION = 657,                   /* UNION  */
    UNIQUE = 658,                  /* UNIQUE  */
    UNKNOWN = 659,                 /* UNKNOWN  */
    UNLISTEN = 660,                /* UNLISTEN  */
    UNLOGGED = 661,                /* UNLOGGED  */
    UNTIL = 662,                   /* UNTIL  */
    UPDATE = 663,                  /* UPDATE  */
    USER = 664,                    /* USER  */
    USING = 665,                   /* USING  */
    VACUUM = 666,                  /* VACUUM  */
    VALID = 667,                   /* VALID  */
    VALIDATE = 668,                /* VALIDATE  */
    VALIDATOR = 669,               /* VALIDATOR  */
    VALUE_P = 670,                 /* VALUE_P  */
    VALUES = 671,                  /* VALUES  */
    VARCHAR = 672,                 /* VARCHAR  */
    VARIADIC = 673,                /* VARIADIC  */
    VARYING = 674,                 /* VARYING  */
    VERBOSE = 675,                 /* VERBOSE  */
    VERSION_P = 676,               /* VERSION_P  */
    VIEW = 677,                    /* VIEW  */
    VIEWS = 678,                   /* VIEWS  */
    VOLATILE = 679,                /* VOLATILE  */
    WHEN = 680,                    /* WHEN  */
    WHERE = 681,                   /* WHERE  */
    WHITESPACE_P = 682,            /* WHITESPACE_P  */
    WINDOW = 683,                  /* WINDOW  */
    WITH = 684,                    /* WITH  */
    WITHIN = 685,                  /* WITHIN  */
    WITHOUT = 686,                 /* WITHOUT  */
    WORK = 687,                    /* WORK  */
    WRAPPER = 688,                 /* WRAPPER  */
    WRITE = 689,                   /* WRITE  */
    XML_P = 690,                   /* XML_P  */
    XMLATTRIBUTES = 691,           /* XMLATTRIBUTES  */
    XMLCONCAT = 692,               /* XMLCONCAT  */
    XMLELEMENT = 693,              /* XMLELEMENT  */
    XMLEXISTS = 694,               /* XMLEXISTS  */
    XMLFOREST = 695,               /* XMLFOREST  */
    XMLNAMESPACES = 696,           /* XMLNAMESPACES  */
    XMLPARSE = 697,                /* XMLPARSE  */
    XMLPI = 698,                   /* XMLPI  */
    XMLROOT = 699,                 /* XMLROOT  */
    XMLSERIALIZE = 700,            /* XMLSERIALIZE  */
    XMLTABLE = 701,                /* XMLTABLE  */
    YEAR_P = 702,                  /* YEAR_P  */
    YES_P = 703,                   /* YES_P  */
    ZONE = 704,                    /* ZONE  */
    NOT_LA = 705,                  /* NOT_LA  */
    NULLS_LA = 706,                /* NULLS_LA  */
    WITH_LA = 707,                 /* WITH_LA  */
    POSTFIXOP = 708,               /* POSTFIXOP  */
    UMINUS = 709                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 202 "src/backend/parser/gram.y"

	core_YYSTYPE		core_yystype;
	/* these fields must match core_YYSTYPE: */
	int					ival;
	char				*str;
	const char			*keyword;

	char				chr;
	bool				boolean;
	JoinType			jtype;
	DropBehavior		dbehavior;
	OnCommitAction		oncommit;
	List				*list;
	Node				*node;
	Value				*value;
	ObjectType			objtype;
	TypeName			*typnam;
	FunctionParameter   *fun_param;
	FunctionParameterMode fun_param_mode;
	ObjectWithArgs		*objwithargs;
	DefElem				*defelt;
	SortBy				*sortby;
	WindowDef			*windef;
	JoinExpr			*jexpr;
	IndexElem			*ielem;
	Alias				*alias;
	RangeVar			*range;
	IntoClause			*into;
	WithClause			*with;
	InferClause			*infer;
	OnConflictClause	*onconflict;
	A_Indices			*aind;
	ResTarget			*target;
	struct PrivTarget	*privtarget;
	AccessPriv			*accesspriv;
	struct ImportQual	*importqual;
	InsertStmt			*istmt;
	VariableSetStmt		*vsetstmt;
	PartitionElem		*partelem;
	PartitionSpec		*partspec;
	PartitionBoundSpec	*partboundspec;
	RoleSpec			*rolespec;

#line 562 "src/backend/parser/gram.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int base_yyparse (core_yyscan_t yyscanner);


#endif /* !YY_BASE_YY_SRC_BACKEND_PARSER_GRAM_H_INCLUDED  */
