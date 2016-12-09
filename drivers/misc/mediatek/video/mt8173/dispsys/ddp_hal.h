#ifndef _H_DDP_HAL_
#define _H_DDP_HAL_

/* DISP Mutex */
#define DISP_MUTEX_TOTAL      (10)
#define DISP_MUTEX_DDP_FIRST  (0)
#define DISP_MUTEX_DDP_LAST   (4)
#define DISP_MUTEX_DDP_COUNT  (5)
#define DISP_MUTEX_MDP_FIRST  (5)
#define DISP_MUTEX_MDP_COUNT  (5)

/* DISP MODULE */
typedef enum {
	DISP_MODULE_CONFIG,
	DISP_MODULE_OVL0,
	DISP_MODULE_OVL1,
	DISP_MODULE_RDMA0,
	DISP_MODULE_RDMA1,
	DISP_MODULE_RDMA2,	/* 5 */
	DISP_MODULE_WDMA0,
	DISP_MODULE_WDMA1,
	DISP_MODULE_COLOR0,
	DISP_MODULE_COLOR1,
	DISP_MODULE_AAL,	/* 10 */
	DISP_MODULE_OD,
	DISP_MODULE_GAMMA,
	DISP_MODULE_MERGE,
	DISP_MODULE_SPLIT0,
	DISP_MODULE_SPLIT1,	/* 15 */
	DISP_MODULE_UFOE,
	DISP_MODULE_DISPATCHER,
	DISP_MODULE_DSI0,
	DISP_MODULE_DSI1,
	DISP_MODULE_DPI0,	/* 20 */
	DISP_MODULE_DPI1,
	DISP_MODULE_PWM0,
	DISP_MODULE_PWM1,
	DISP_MODULE_MUTEX,
	DISP_MODULE_SMI_LARB0,	/* 25 */
	DISP_MODULE_SMI_COMMON,
	DISP_MODULE_HDMI,
	DISP_MODULE_LVDS,
	DISP_MODULE_LARB4,
	DISP_MODULE_MIPITX0,	/* 30 */
	DISP_MODULE_MIPITX1,
	DISP_MODULE_DSIDUAL,
	DISP_MODULE_CMDQ,
	DISP_MODULE_IO_DRIVING,
	DISP_MODULE_TVDPLL_CFG6,
	DISP_MODULE_TVDPLL_CON0,
	DISP_MODULE_TVDPLL_CON1,
	DISP_MODULE_UNKNOWN,
	DISP_MODULE_NUM
} DISP_MODULE_ENUM;

typedef enum {
	SOF_SINGLE = 0,
	SOF_DSI0,
	SOF_DSI1,
	SOF_DPI0,
} MUTEX_SOF;

enum OVL_LAYER_SOURCE {
	OVL_LAYER_SOURCE_MEM = 0,
	OVL_LAYER_SOURCE_RESERVED = 1,
	OVL_LAYER_SOURCE_SCL = 2,
	OVL_LAYER_SOURCE_PQ = 3,
};

enum OVL_LAYER_SECURE_MODE {
	OVL_LAYER_NORMAL_BUFFER = 0,
	OVL_LAYER_SECURE_BUFFER = 1,
	OVL_LAYER_PROTECTED_BUFFER = 2
};

typedef enum {
	CMDQ_DISABLE = 0,
	CMDQ_ENABLE
} CMDQ_SWITCH;

typedef enum {
	CMDQ_BEFORE_STREAM_SOF,
	CMDQ_WAIT_STREAM_EOF_EVENT,
	CMDQ_CHECK_IDLE_AFTER_STREAM_EOF,
	CMDQ_AFTER_STREAM_EOF,
	CMDQ_ESD_CHECK_READ,
	CMDQ_ESD_CHECK_CMP,
	CMDQ_ESD_ALLC_SLOT,
	CMDQ_ESD_FREE_SLOT,
	CMDQ_STOP_VDO_MODE,
	CMDQ_START_VDO_MODE,
	CMDQ_DSI_RESET
} CMDQ_STATE;

/* MM_SYS_CLK */
typedef enum {
	MM_CLK_CAM_MDP,
	MM_CLK_MDP_RDMA0,
	MM_CLK_MDP_RDMA1,	/*5 */
	MM_CLK_MDP_RSZ0,
	MM_CLK_MDP_RSZ1,
	MM_CLK_MDP_RSZ2,
	MM_CLK_MDP_TDSHP0,
	MM_CLK_MDP_TDSHP1,	/*10 */
	MM_CLK_MDP_WDMA,
	MM_CLK_MDP_WROT0,
	MM_CLK_MDP_WROT1,
	MM_CLK_FAKE_ENG,
	MM_CLK_MUTEX_32K,	/*15 */
	MM_CLK_DISP_OVL0,
	MM_CLK_DISP_OVL1,
	MM_CLK_DISP_RDMA0,
	MM_CLK_DISP_RDMA1,
	MM_CLK_DISP_RDMA2,	/*20 */
	MM_CLK_DISP_WDMA0,
	MM_CLK_DISP_WDMA1,
	MM_CLK_DISP_COLOR0,
	MM_CLK_DISP_COLOR1,
	MM_CLK_DISP_AAL,	/*25 */
	MM_CLK_DISP_GAMMA,
	MM_CLK_DISP_UFOE,
	MM_CLK_DISP_SPLIT0,
	MM_CLK_DISP_SPLIT1,
	MM_CLK_DISP_MERGE,	/*30 */
	MM_CLK_DISP_OD,
	MM_CLK_DISP_PWM0MM,
	MM_CLK_DISP_PWM026M,
	MM_CLK_DISP_PWM1MM,
	MM_CLK_DISP_PWM126M,	/*35 */
	MM_CLK_DSI0_ENGINE,
	MM_CLK_DSI0_DIGITAL,
	MM_CLK_DSI1_ENGINE,
	MM_CLK_DSI1_DIGITAL,
	MM_CLK_DPI_PIXEL,	/*40 */
	MM_CLK_DPI_ENGINE,
	MM_CLK_DPI1_PIXEL,
	MM_CLK_DPI1_ENGINE,
	/*MM_CLK_HDMI_PIXEL, */
	/*MM_CLK_HDMI_PLLCK,    *//*45 */
	/*MM_CLK_HDMI_AUDIO, */
	/*MM_CLK_HDMI_SPDIF, */
	MM_CLK_LVDS_PIXEL,
	MM_CLK_LVDS_CTS,
	MM_CLK_MUX_DPI0_SEL,
	/* MM_CLK_HDMI_HDCP, */
	/* MM_CLK_HDMI_HDCP_24M, */
	APMIXED_TVDPLL,
	TOP_TVDPLL_D2,
	TOP_TVDPLL_D4,
	TOP_TVDPLL_D8,
	TOP_TVDPLL_D16,
	APMIXED_LVDSPLL,
	TOP_DPILVDS_SEL,
	/* TOP_AD_LVDSPLL_CK, //replace with MMSYS_APMIXED_LVDSPLL */
	TOP_LVDSPLL_D2,
	TOP_LVDSPLL_D4,
	TOP_LVDSPLL_D8,
	MM_CLK_NUM
} MM_CLK_ENUM;

#endif
