# Omi C++ Formats

Omi C++ Formats provide source generated C++ programs that read packet captures of common binary exchange protocols and write their messages out in other formats. Every program reads its capture through the Advanced parser under `cpp/advanced/`, and every format is written from one translation of its protocol, so a value carries the same name and the same meaning wherever it is written.

## Formats

Each top-level directory holds one kind of format, with a directory for each way of writing it. A format's ReadMe shows how to use its programs, what its build needs, and lists its organizations and protocols.

| Format | Description |
| --- | --- |
| [json](json) | [native json](json/native), [rapid json](json/rapid) |
| [parquet](parquet) | [wide parquet](parquet/wide) |
| [avro](avro) | [wide avro (native)](avro/wide/native), [wide avro (c)](avro/wide/c), [tree avro (native)](avro/tree/native), [tree avro (c)](avro/tree/c) |

## Usage

The repository is one CMake build, with a program for each protocol in each format. Build every one:

```
cmake -S . -B build && cmake --build build --parallel $(nproc)
```

Each program reads a capture and writes what its messages hold, and is named for its format and protocol:

```
./build/json_native_<protocol> capture.pcap [output.jsonl]
./build/json_rapid_<protocol> capture.pcap [output.jsonl]
./build/parquet_wide_<protocol> capture.pcap out.parquet
./build/avro_wide_native_<protocol> capture.pcap out.avro
./build/avro_wide_c_<protocol> capture.pcap out.avro
./build/avro_tree_native_<protocol> capture.pcap out.avro
./build/avro_tree_c_<protocol> capture.pcap out.avro
```

## Development

Updates are greatly appreciated; however, this entire repository is source generated...including the words you are reading right now. If you wish to suggest updates, the recommended process is to create an issue with changes and explanation.  Time permitting, we will update the models and regenerate.

| Protocols | Formats | Generated Lines |
| ---: | ---: | ---: |
| 25 | 7 | 293,981 |

## Testing

[![Build](https://github.com/Open-Markets-Initiative/omi-cpp-formats/actions/workflows/build.yml/badge.svg)](https://github.com/Open-Markets-Initiative/omi-cpp-formats/actions/workflows/build.yml)

Every build compiles each protocol's writers in every format, and runs 105 corpus tests, each writing every message of a protocol's captures from [omi-data-pcaps](https://github.com/Open-Markets-Initiative/omi-data-pcaps) and reading the result back; see each format's ReadMe.

A protocol that cannot be read is left out of every format:

- `Iex.IexEquities.Deep.Snap.v1.6`: no transport sequence for the Advanced session layer to walk a capture with
- `Iex.IexEquities.DeepPlus.Snap.v1.06`: no transport sequence for the Advanced session layer to walk a capture with
- `Iex.IexEquities.Tops.Snap.v1.6`: no transport sequence for the Advanced session layer to walk a capture with

Please report any errors as an [issue](https://github.com/Open-Markets-Initiative/omi-cpp-formats/issues "Omi C++ Formats Issues").  Include a small note on the protocol and version, and a minimal capture demonstrating the problem. Also consider including a link or pdf specification documenting the correct behavior.

Production packet captures are required for protocol verification.  If your organization has the rights to packet captures, and you wish to make the world a better place, please post captures to this project.

## Open Markets Initiative

[![Omi](https://github.com/Open-Markets-Initiative/Open-Markets-Initiative/raw/main/About/Images/Logo.png)](https://github.com/Open-Markets-Initiative/Directory)

The Open Markets Initiative (Omi) is a group of technologists dedicated to enhancing the stability of electronic financial markets using modern development methods.

Other generated code can be found at [Omi Repositories](https://github.com/Open-Markets-Initiative/Directory/tree/main/Repositories "Open Markets Initiative Repositories"); for Omi rules and regulations, see [Omi Directory](https://github.com/Open-Markets-Initiative/Directory "Open Markets Initiative Directory").

## Disclaimer

Any similarities between existing people, places and/or protocols is purely incidental.

Enjoy.
