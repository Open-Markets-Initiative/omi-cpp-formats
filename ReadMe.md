# Omi C++ Formats

Generated C++ programs that read packet captures and write their messages out in other formats.
The repository is purely historical: every program reads a pcap and writes what it holds.

Each protocol carries the Advanced parser every program reads through under `cpp/advanced/`, and
each format has a directory of its own:

- `json/native/` — writers that turn every message into a flat JSON object without a JSON library
- `json/rapid/` — writers that turn every message into the same object through RapidJSON
- `parquet/wide/` — one table per protocol, a column for every value any of its messages holds
- `avro/wide/native/` — every message as one wide record of the values any message holds, written without an Avro library
- `avro/wide/c/` — every message as one wide record of the values any message holds, written through Apache Avro's C library
- `avro/tree/native/` — every message as a record of its own, holding what it holds as the model declares it, written without an Avro library
- `avro/tree/c/` — every message as a record of its own, holding what it holds as the model declares it, written through Apache Avro's C library

```sh
cmake -S . -B build && cmake --build build --parallel $(nproc)
```

## Development

Updates are greatly appreciated; however, this entire repository is source generated. If you wish to suggest updates, the recommended process is to create an issue with changes and explanation.

| Format | Protocol Count | Generated Lines |
| --- | --- | --- |
| Advanced parser | 22 | 113,785 |
| native json | 22 | 8,630 |
| rapid json | 22 | 8,990 |
| wide parquet | 22 | 25,895 |
| wide avro (native) | 22 | 22,858 |
| wide avro (c) | 22 | 22,776 |
| tree avro (native) | 22 | 9,294 |
| tree avro (c) | 22 | 9,212 |

| Organization | Protocol Count | Generated Lines |
| --- | --- | --- |
| Iex | 7 | 42,784 |
| Nasdaq | 15 | 176,523 |

## Programs

Each format has one program per protocol, under `executables/<format>/<protocol>/`. Every one reads a
capture through the Advanced session layer and writes what its messages hold:

```sh
./build/json_native_<protocol> capture.pcap [output.jsonl]
./build/json_rapid_<protocol> capture.pcap [output.jsonl]
./build/parquet_wide_<protocol> capture.pcap out.parquet
./build/avro_wide_native_<protocol> capture.pcap out.avro
./build/avro_wide_c_<protocol> capture.pcap out.avro
./build/avro_tree_native_<protocol> capture.pcap out.avro
./build/avro_tree_c_<protocol> capture.pcap out.avro
```

Every format is written from one translation of its protocol, so a value carries the same name and the
same meaning wherever it is written: an enumeration by its value's name, text trimmed, a price or other
decimal kept exactly from its mantissa and its exponent, and an absent optional value as null.

## Formats

**native json** — writers that turn every message into a flat JSON object without a JSON library. It needs nothing beyond the compiler.

**rapid json** — writers that turn every message into the same object through RapidJSON. It needs `rapidjson-dev` (on Ubuntu).

**wide parquet** — one table per protocol, a column for every value any of its messages holds. It needs `libarrow-dev` and `libparquet-dev` (on Ubuntu).

**wide avro (native)** — every message as one wide record of the values any message holds, written without an Avro library. It needs nothing beyond the compiler.

**wide avro (c)** — every message as one wide record of the values any message holds, written through Apache Avro's C library. It needs `libavro-dev` (on Ubuntu).

**tree avro (native)** — every message as a record of its own, holding what it holds as the model declares it, written without an Avro library. It needs nothing beyond the compiler.

**tree avro (c)** — every message as a record of its own, holding what it holds as the model declares it, written through Apache Avro's C library. It needs `libavro-dev` (on Ubuntu).

## Tests

`tests/<format>/` walks every capture a protocol declares, writes every message it holds through that
format and reads the result back (84 tests). A capture
named for one message must hold it; a session capture names none, and is held to what it holds.
The captures are the session captures of
[omi-data-pcaps](https://github.com/Open-Markets-Initiative/omi-data-pcaps), read compressed:

```sh
git clone --depth=1 https://github.com/Open-Markets-Initiative/omi-data-pcaps.git
cmake -S . -B build -DOMI_PACKETS_DIR=omi-data-pcaps
cmake --build build --parallel $(nproc) && ctest --test-dir build
```

Every build also compiles `checks/`, one translation unit per protocol and format holding nothing but
an include of its writers, so a writer that does not compile fails the build whether or not the corpus
has a capture to run it against.

A protocol that cannot be written is left out, of every format or of the one named:

- Iex.IexEquities.Deep.Snap.v1.6: no transport sequence for the Advanced session layer to walk a capture with
- Iex.IexEquities.DeepPlus.Snap.v1.06: no transport sequence for the Advanced session layer to walk a capture with
- Iex.IexEquities.Tops.Snap.v1.6: no transport sequence for the Advanced session layer to walk a capture with

## Protocols (22)

- `Iex.IexEquities.Deep.IexTp.v1.06`
- `Iex.IexEquities.Deep.IexTp.v1.08`
- `Iex.IexEquities.DeepPlus.IexTp.v1.01`
- `Iex.IexEquities.DeepPlus.IexTp.v1.05`
- `Iex.IexEquities.Tops.IexTp.v1.56`
- `Iex.IexEquities.Tops.IexTp.v1.64`
- `Iex.IexEquities.Tops.IexTp.v1.66`
- `Nasdaq.NsmEquities.Aggregated.Itch.v2.0`
- `Nasdaq.NsmEquities.Level2.Itch.v2.0`
- `Nasdaq.NsmEquities.NlsPlus.Itch.v3.0`
- `Nasdaq.NsmEquities.NlsPlus.Itch.v4.0`
- `Nasdaq.NsmEquities.NoiView.Itch.v3.0.2017`
- `Nasdaq.NsmEquities.NoiView.Itch.v3.0.2026`
- `Nasdaq.NsmEquities.Nois.Itch.v2.2`
- `Nasdaq.NsmEquities.Nois.Itch.v2.2.2022`
- `Nasdaq.NsmEquities.Qbbo.Itch.v2.1`
- `Nasdaq.NsmEquities.TotalView.Itch.v4.1`
- `Nasdaq.NsmEquities.TotalView.Itch.v5.0.2017`
- `Nasdaq.NsmEquities.TotalView.Itch.v5.0.2018`
- `Nasdaq.NsmEquities.TotalView.Itch.v5.0.2022`
- `Nasdaq.NsmEquities.TotalView.Itch.v5.0.2023`
- `Nasdaq.NsmEquities.TotalView.Itch.v5.0.2026`

Regenerated by `Generate.Cpp.Formats.Repository`; do not edit by hand.
