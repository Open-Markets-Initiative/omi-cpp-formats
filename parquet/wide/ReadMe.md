# parquet/wide

One table per protocol, a column for every value any of its messages holds. It needs `libarrow-dev` and `libparquet-dev` (on Ubuntu).

## Usage

Each protocol has one program, built with the repository, which reads a capture through the Advanced session layer and writes what its messages hold, such as `Iex.IexEquities.Deep.IexTp.v1.06`:

```
./build/parquet_wide_iex_iexequities_deep_iextp_v1.06 capture.pcap out.parquet
```

A protocol delivered as files reads a file in place of a capture, gzip or plain, through the Advanced file layer (`messages/file.hpp`): the file's first bytes are checked against the constants the model says it opens with, what it opens with is stepped over, and every record after it is framed by its own length.

Every value is written as the translation of its protocol gives it: an enumeration by its value's name, text trimmed, a price or other decimal kept exactly from its mantissa and its exponent, and an absent optional value as null.

## Directories

Each protocol's files are under its organization, division, protocol and version, as its Advanced parser's are under `cpp/advanced/`:

| Path | Description |
| --- | --- |
| `parquet/wide/` | What every protocol's writers share |
| `parquet/wide/<protocol>/Record.hpp` | A protocol's writers, reading its messages through its Advanced parser |
| `executables/parquet/wide/<protocol>/main.cpp` | A protocol's program, reading a capture and writing it out |
| `tests/parquet/wide/<protocol>.cpp` | A protocol's corpus test, where its captures name a message it writes |
| `checks/<protocol>_parquet_wide.cpp` | A translation unit including nothing but a protocol's writers, so a writer that does not compile fails the build |

## Testing

Each corpus test walks every capture a protocol declares, writes every message it holds and reads the result back (15 tests). A capture named for one message must hold it; a session capture names none, and is held to what it holds. The captures are the session captures of [omi-data-pcaps](https://github.com/Open-Markets-Initiative/omi-data-pcaps), read compressed. The same run, locally, for this format alone:

```
git clone --depth=1 https://github.com/Open-Markets-Initiative/omi-data-pcaps.git
cmake -S . -B build -DOMI_PACKETS_DIR=omi-data-pcaps
cmake --build build --parallel $(nproc)
ctest --test-dir build -R '^parquet_wide_'
```

A protocol delivered as files is tested over its file excerpts instead: whole files of the corpus, gzipped, each named for the record it carries, read through the file layer.

## Organizations

| Organization | Protocols | Generated Lines |
| --- | ---: | ---: |
| Databento | 3 | 10,701 |
| Iex | 7 | 4,032 |
| Nasdaq | 15 | 21,727 |

## Protocols (25)

- `Databento.MarketData.Normalized.Dbn.v1`
- `Databento.MarketData.Normalized.Dbn.v2`
- `Databento.MarketData.Normalized.Dbn.v3`
- `Iex.IexEquities.Deep.IexTp.v1.06`
- `Iex.IexEquities.Deep.IexTp.v1.08`
- `Iex.IexEquities.DeepPlus.IexTp.v1.01`
- `Iex.IexEquities.DeepPlus.IexTp.v1.05`
- `Iex.IexEquities.Tops.IexTp.v1.56`
- `Iex.IexEquities.Tops.IexTp.v1.64`
- `Iex.IexEquities.Tops.IexTp.v1.66`
- `Nasdaq.NsmEquities.Aggregated.Itch.v2.0`
- `Nasdaq.NsmEquities.Level2.Itch.v2.0.2026`
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

