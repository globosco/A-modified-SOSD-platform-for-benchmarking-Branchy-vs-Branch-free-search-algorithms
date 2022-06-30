


# Modified Search on Sorted Data Benchmark for Branchy vs Branchfree study


[SOSD](https://learned.systems/papers/sosd.pdf) is a benchmark to compare (learned) index structures on equality lookup performance over densely packed, sorted data.
The original version of SOSD can be downloaded at [Github](https://github.com/learnedsystems/SOSD).
This modified version is designed to replicate the results presented in our paper at [ArXiv](https://arxiv.org/abs/2201.01554) concerning the comparison between Branchy and Banchfree algorithms using the best Learned Indexes in the Literature.

## Principal modifications

We added some search routines to the ones provided by the platform. In particular, we provide the following methods.

1  Uniform Binary, 
1 Uniform and Standard k-ary Search 
1 Search layouts other than sorted, i.e. Eytzinger Layout

We provide also the scripts to execute allo of them on datasets linked in the dedicated Section.

## Dependencies

Dependencies are the same of the original software. We repeat them here for completness.

On vanilla Ubuntu 20.04 LTS:

```
sudo apt -y update
sudo apt -y install zstd python3-pip m4 cmake clang libboost-all-dev
pip3 install --user numpy scipy
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
source $HOME/.cargo/env
```

## Datasets

Datasets used in this work can be downloaded at https://math.unipa.it/lobosco/LSTS/
All downloaded files must be placed in the data folder located in the repository root before running the benchmark scripts.

## Usage instructions

We provide a number of scripts to automate things. Each is located in the `scripts` directory, but should be executed from the repository root.

## Running the benchmark

* `./scripts/build_rmis.sh` compiles and builds the RMIs for each dataset
* `./scripts/prepare.sh` constructs query workloads and compiles the benchmark
* `./scripts/execute_all.sh` executes the benchmark on each workload and with all the search methods used in the work, storing the results in `results`. This script returns the results as csv files.

## Cite

If you use this benchmark in your own work, please cite us:

```
@misc{amato2022standard,
      title={Standard Vs Uniform Binary Search and Their Variants in Learned Static Indexing: The Case of the Searching on Sorted Data Benchmarking Software Platform}, 
      author={Domenico Amato and Giosuè Lo Bosco and Raffaele Giancarlo},
      year={2022},
      eprint={2201.01554},
      archivePrefix={arXiv},
      primaryClass={cs.DS}
}
```

and the original works:

```
@article{sosd-vldb,
  author    = {Ryan Marcus and
               Andreas Kipf and
               Alexander van Renen and
               Mihail Stoian and
               Sanchit Misra and
               Alfons Kemper and
               Thomas Neumann and
               Tim Kraska},
  title     = {Benchmarking Learned Indexes},
  journal   = {Proc. {VLDB} Endow.},
  volume    = {14},
  number    = {1},
  pages     = {1--13},
  year      = {2020}
}

@article{sosd-neurips,
  title={SOSD: A Benchmark for Learned Indexes},
  author={Kipf, Andreas and Marcus, Ryan and van Renen, Alexander and Stoian, Mihail and Kemper, Alfons and Kraska, Tim and Neumann, Thomas},
  journal={NeurIPS Workshop on Machine Learning for Systems},
  year={2019}
}
```


