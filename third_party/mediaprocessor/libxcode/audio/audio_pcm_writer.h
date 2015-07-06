/****************************************************************************
 *
 * <COPYRIGHT_TAG>
 *
 ****************************************************************************/

#ifndef __AUDIOPCMWRITER_H__
#define __AUDIOPCMWRITER_H__
#include "base/base_element.h"
#include "base/media_common.h"
#include "base/stream.h"
#include "wave_header.h"
#include "audio_params.h"
#include "base/measurement.h"

class AudioPCMWriter : public BaseElement
{
public:
    AudioPCMWriter(Stream* st, unsigned char* name);
    virtual ~AudioPCMWriter();
    virtual bool Init(void *cfg, ElementMode element_mode);
    virtual int Recycle(MediaBuf &buf);
    virtual int ProcessChain(MediaPad *pad, MediaBuf &buf);
    virtual int HandleProcess();
private:
    AudioPCMWriter();
    void Release();
    int PCMWrite(AudioPayload* payload_in);
protected:
    Stream*                       stream_writer_;
    AudioStreamInfo               stream_info_;
    Info                          wav_info_;
    WaveHeader                    wav_header_;
    Stream*                       dump_output_;
    unsigned long long            data_size_;
    unsigned int                  frame_count_;
    Measurement                   measure_;
    unsigned long                 cur_time_;
    unsigned long                 start_time_;
    StreamType                    enc_type_;
    unsigned char                 *buf_enc_;
};

#endif // __AUDIOPCMWRITER_H__
