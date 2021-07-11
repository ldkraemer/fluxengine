#ifndef NORTHSTAR_H
#define NORTHSTAR_H

/* Northstar floppies are 10-hard sectored disks with a sector format as follows:
 *
 * |----------------------------------|
 * | SYNC Byte  | Payload  | Checksum |
 * |------------+----------+----------|
 * | 1 (0xFB)   | 256 (SD) |    1     |
 * | 2 (0xFBFB) | 512 (DD) |          |
 * |----------------------------------|
 *
 */

#include "decoders/decoders.h"
#include "encoders/encoders.h"

#define NORTHSTAR_PREAMBLE_SIZE_SD		(16)
#define NORTHSTAR_PREAMBLE_SIZE_DD		(32)
#define NORTHSTAR_HEADER_SIZE_SD		(1)
#define NORTHSTAR_HEADER_SIZE_DD		(2)
#define NORTHSTAR_PAYLOAD_SIZE_SD		(256)
#define NORTHSTAR_PAYLOAD_SIZE_DD		(512)
#define NORTHSTAR_CHECKSUM_SIZE		(1)
#define NORTHSTAR_ENCODED_SECTOR_SIZE_SD	(NORTHSTAR_HEADER_SIZE_SD + NORTHSTAR_PAYLOAD_SIZE_SD + NORTHSTAR_CHECKSUM_SIZE)
#define NORTHSTAR_ENCODED_SECTOR_SIZE_DD	(NORTHSTAR_HEADER_SIZE_DD + NORTHSTAR_PAYLOAD_SIZE_DD + NORTHSTAR_CHECKSUM_SIZE)

#define SECTOR_TYPE_MFM			(0)
#define SECTOR_TYPE_FM				(1)

class NorthstarEncoderProto;
class NorthstarDecoderProto;

class NorthstarEncoder : public AbstractEncoder
{
public:
	NorthstarEncoder(const NorthstarEncoderProto& config):
		_config(config)
	{}

	virtual ~NorthstarEncoder() {}
	std::unique_ptr<Fluxmap> encode(int physicalTrack, int physicalSide, const SectorSet& allSectors);

private:
	const NorthstarEncoderProto& _config;
};

extern FlagGroup northstarEncoderFlags;
extern uint8_t northstarChecksum(const Bytes& bytes);

extern std::unique_ptr<AbstractDecoder> createNorthstarDecoder(const DecoderProto& config);

#endif /* NORTHSTAR */
