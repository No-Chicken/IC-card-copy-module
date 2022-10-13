#include "idcopy.h"

uint8_t status;
unsigned char snr, TagType[2], SelectedSnr[4], DefaultKey[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

/**************************************************************************/
/*!
    @brief  init

		@returns the status,0 if success
*/
/**************************************************************************/ 
uint8_t id_copy_init()
{
	uint8_t num;
	IC_card_Init();
	num = RC522_Init();
	return num;
}
/**************************************************************************/
/*!
    @brief  use the module to write to the card self(copy the outside card)

		@param  *write_buf		the buffer of write

		@returns the status,0 if success
*/
/**************************************************************************/ 
uint8_t idcopy_write(uint8_t *write_buf)
{
	IC_card_Enable();
	HAL_Delay(1);
	status= PcdRequest(REQ_ALL,TagType);
	if(!status)
	{
		status = PcdAnticoll(SelectedSnr);
		if(!status)
		{
			status=PcdSelect(SelectedSnr);
			if(!status)
			{
				snr = 0;  //sector 0
				status = PcdAuthState(KEYA, (snr*4+3), DefaultKey, SelectedSnr);
				{
					if(!status)
					{ 
						status = PcdWrite((snr*4+0), write_buf);  
						if(!status)
						{
							return 0;
							WaitCardOff();
							//return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}
/**************************************************************************/
/*!
    @brief  use the module to read the idcard

		@param  *read_buf		the buffer of read

		@returns the status,0 if success
*/
/**************************************************************************/ 
uint8_t idcopy_read(uint8_t *read_buf)
{
	IC_card_Disable();
	HAL_Delay(1);
	status= PcdRequest(REQ_ALL,TagType);
	if(!status)
	{
		status = PcdAnticoll(SelectedSnr);
		if(!status)
		{
			status=PcdSelect(SelectedSnr);
			if(!status)
			{
				snr = 0;  //sector 0
				status = PcdAuthState(KEYA, (snr*4+3), DefaultKey, SelectedSnr);
				{
					if(!status)
					{
						status = PcdRead((snr*4+0), read_buf);  
						if(!status)
						{
							return 0;
							WaitCardOff();
							//return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}
